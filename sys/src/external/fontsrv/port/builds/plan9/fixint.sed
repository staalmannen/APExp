# fix the (uint) <= (int) comparison in src/truetype/ttgload.c versions 2.13.3+
/FT_NEXT_USHORT/,/Invalid_Outline/{
	/\*cont <= last/ {
		/FT_Int/n
		s/\*cont/(FT_Int)*cont/
	}
}
