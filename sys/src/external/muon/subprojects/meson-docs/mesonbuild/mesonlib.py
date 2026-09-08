import typing as T


def listify(item: T.Any, flatten: bool = True) -> T.List[T.Any]:
    """
    Returns a list with all args embedded in a list if they are not a list.
    This function preserves order.
    @flatten: Convert lists of lists to a flat list
    """
    if not isinstance(item, list):
        return [item]
    result = []  # type: T.List[T.Any]
    for i in item:
        if flatten and isinstance(i, list):
            result += listify(i, flatten=True)
        else:
            result.append(i)
    return result


class MesonException(Exception):
    """Exceptions thrown by Meson"""

    def __init__(
        self,
        *args: object,
        file: T.Optional[str] = None,
        lineno: T.Optional[int] = None,
        colno: T.Optional[int] = None
    ):
        super().__init__(*args)
        self.file = file
        self.lineno = lineno
        self.colno = colno


def relpath(path: str, start: str) -> str:
    # On Windows a relative path can't be evaluated for paths on two different
    # drives (i.e. c:\foo and f:\bar).  The only thing left to do is to use the
    # original absolute path.
    try:
        return os.path.relpath(path, start)
    except (TypeError, ValueError):
        return path
