# SPDX-License-Identifier: Apache-2.0
# Copyright 2021 The Meson development team
from __future__ import annotations

from pathlib import Path
import json
import re

from .generatorbase import GeneratorBase
from . import jsonschema as J
from .model import (
	ReferenceManual,
	Function,
	Object,
	Type,

	PosArg,
	VarArgs,
	Kwarg,
)

import typing as T

OBJ_MAP = {
	'build_machine': 'machine',
	'build_tgt': 'build_target',
	'cfg_data': 'configuration_data',
	'cmake': None,
	'cmake_options': None,
	'custom_idx': None,
	'custom_tgt': 'custom_target',
	'dep': 'dependency',
	'env': 'environment',
	'feature': 'feature_opt',
	'int': 'number',
	'list': 'array',
	'runresult': 'run_result',
	'str': 'string',
}

class GeneratorC(GeneratorBase):
	def __init__(self, manual: ReferenceManual, out: Path, enable_modules: bool) -> None:
		super().__init__(manual)
		self.out = out
		self.enable_modules = enable_modules

	def _generate_type(self, typ: Type) -> T.List[J.Type]:
		return [
			{
				'obj': x.data_type.name,
				'holds': self._generate_type(x.holds) if x.holds else [],
			}
			for x in typ.resolved
		]

	def _generate_type_str(self, typ: Type) -> str:
		# Remove all whitespaces
		return re.sub(r'[ \n\r\t]', '', typ.raw)

	def _generate_arg(self, arg: T.Union[PosArg, VarArgs, Kwarg], isOptarg: bool = False) -> J.Argument:
		return {
			'name': arg.name,
			'description': arg.description,
			'since': arg.since if arg.since else None,
			'deprecated': arg.deprecated if arg.deprecated else None,
			'type': self._generate_type(arg.type),
			'type_str': self._generate_type_str(arg.type),
			'required': arg.required if isinstance(arg, Kwarg) else not isOptarg and not isinstance(arg, VarArgs),
			'default': arg.default if isinstance(arg, (PosArg, Kwarg)) else None,
			'min_varargs': arg.min_varargs if isinstance(arg, VarArgs) and arg.min_varargs > 0 else None,
			'max_varargs': arg.max_varargs if isinstance(arg, VarArgs) and arg.max_varargs > 0 else None,

			# Not yet supported
			'notes': [],
			'warnings': [],
		}

	def _cstr(self, s: str) -> str:
		s = s.replace('\\', '\\\\')
		s = s.replace('\n', '\\n')
		s = s.replace('"', '\\"')
		return f'"{s}"'

	def _wrap(self, s):
		return f"{{ {s} }}"

	def _cstr_struct(self, d):
		elems = []
		for k, v in d.items():
			if v is True:
				s = "true"
			elif v is False:
				s = "false"
			elif type(v) is int:
				s = str(v)
			else:
				s = self._cstr(v)

			elems.append(f".{k} = {s}")

		return self._wrap(', '.join(elems))

	def _generate_function(self, func: Function) -> str:
		posargs = []
		kwargs = []

		for arg in func.posargs:
			posargs.append({
				'common.name': arg.name,
				'common.description': arg.description,
				'common.type': self._generate_type_str(arg.type),
			})

		for arg in func.optargs:
			posargs.append({
				'common.name': arg.name,
				'common.description': arg.description,
				'common.type': self._generate_type_str(arg.type),
				'optional': True,
			})

		if func.varargs:
			posargs.append({
				'common.name': func.varargs.name,
				'common.description': func.varargs.description,
				'common.type': self._generate_type_str(func.varargs.type),
				'glob': True,
			})

		for arg in self.sorted_and_filtered(list(func.kwargs.values())):
			kwargs.append({
				'common.name': arg.name,
				'common.description': arg.description,
				'optional': True,
			})

		return {
			'common.name': func.name,
			'common.description': func.description,
			'common.type': self._generate_type_str(func.returns),
			'posargs_len': len(posargs),
			'kwargs_len': len(kwargs),
		}, posargs, kwargs

		#	 'since': func.since if func.since else None,
		#	 'deprecated': func.deprecated if func.deprecated else None,
		#	 'notes': func.notes,
		#	 'warnings': func.warnings,
		#	 'example': func.example if func.example else None,
		#	 'returns': self._generate_type(func.returns),
		#	 'returns_str': self._generate_type_str(func.returns),
		#	 'posargs': {x.name: self._generate_arg(x) },
		#	 'optargs': {x.name: self._generate_arg(x, True) for x in func.optargs},
		#	 'kwargs': {x.name: self._generate_arg(x) for x in self.sorted_and_filtered(list(func.kwargs.values()))},
		#	 'varargs': self._generate_arg(func.varargs) if func.varargs else None,
		#	 'arg_flattening': func.arg_flattening,
		# }

	def _generate_objects(self, obj: Object) -> J.Object:
		return {
			'name': obj.name,
			'description': obj.description,
			'since': obj.since if obj.since else None,
			'deprecated': obj.deprecated if obj.deprecated else None,
			'notes': obj.notes,
			'warnings': obj.warnings,
			'defined_by_module': obj.defined_by_module.name if obj.defined_by_module else None,
			'object_type': obj.obj_type.name,
			'is_container': obj.is_container,
			'example': obj.example if obj.example else None,
			'extends': obj.extends if obj.extends else None,
			'returned_by': [x.name for x in self.sorted_and_filtered(obj.returned_by)],
			'extended_by': [x.name for x in self.sorted_and_filtered(obj.extended_by)],
			'methods': {x.name: self._generate_function(x) for x in self.sorted_and_filtered(obj.methods)},
		}

	def generate(self) -> None:
		prefix = 'meson_doc_'
		text = ''

		posargs = []
		kwargs = []
		funcs = { '0': [] }

		def add_function(group_name, func):
			f, p, k = self._generate_function(func)
			f['posargs_start'] = len(posargs)
			f['kwargs_start'] = len(kwargs)
			funcs[group_name].append(self._cstr_struct(f))
			posargs.extend([self._cstr_struct(x) for x in p])
			kwargs.extend([self._cstr_struct(x) for x in k])

		for x in self.sorted_and_filtered(self.functions):
			add_function('0', x)

		for x in self.sorted_and_filtered(self.objects):
			if x.name in OBJ_MAP:
				o = OBJ_MAP[x.name]
			else:
				o = x.name

			if o is None:
				continue

			o = f'obj_{o}'

			for y in self.sorted_and_filtered(x.methods):
				if o not in funcs:
					funcs[o] = []
				add_function(o, y)

		text += f'struct {prefix}entry_arg {prefix}posargs[] = {{\n'
		for o in posargs:
			text += f'\t{o},\n'

		text += '};\n'

		text += f'struct {prefix}entry_arg {prefix}kwargs[] = {{\n'
		for o in kwargs:
			text += f'\t{o},\n'

		text += '};\n'

		for o in funcs:
			text += f'struct {prefix}entry_func {prefix}object_{o}[] = {{\n'

			for f in funcs[o]:
				text += '\t' + f + ',\n'

			text += '\t{ 0 },\n'

			text += '};\n\n'

		text += f'struct {prefix}entry_func *{prefix}root[obj_type_count] = {{\n'

		for o in funcs:
			text += f'\t[{o}] = {prefix}object_{o},\n'

		text += '};\n'

		self.out.write_text(
			text.lstrip(),
			encoding='utf-8',
		)

		# data: J.Root = {
		#	 'version_major': J.VERSION_MAJOR,
		#	 'version_minor': J.VERSION_MINOR,
		#	 'meson_version': self._extract_meson_version(),
		#	 'functions': {x.name: self._generate_function(x) for x in self.sorted_and_filtered(self.functions)},
		#	 'objects': {x.name: self._generate_objects(x) for x in self.sorted_and_filtered(self.objects)},
		#	 'objects_by_type': {
		#		 'elementary': [x.name for x in self.elementary],
		#		 'builtins': [x.name for x in self.builtins],
		#		 'returned': [x.name for x in self.returned],
		#		 'modules': {
		#			 x.name: [y.name for y in self.sorted_and_filtered(self.extract_returned_by_module(x))]
		#			 for x in self.modules
		#		 },
		#	 },
		# }

		# self.out.write_text(json.dumps(data), encoding='utf-8')
