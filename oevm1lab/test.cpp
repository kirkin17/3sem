

void invert(int *value, short first, short number)
{
	short byte = 0;
	for (short i = sizeof(*value); i != 0; i--)
	{
		*value >> (8 * (i - 1));
		for (unsigned char mask = pow(2, 7); mask != 0; mask >>= 1)
		{
			bool a = (*value & mask);
			++byte;
			if (byte == first)
			{
				*value ^= mask;
			}
			cout << a;
		}
		cout << " ";
	}
}