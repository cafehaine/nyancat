#include <iostream>
#include <vector>
#include <string>

using namespace std;

static int steps[] = {0,63,127,190};
static istream& stream = cin;

// returns a color code in the following format:
// r;g;b
// pos varies from 0 to 23
string test(int pos)
{
	int r = 0, g = 0, b = 0;

	switch (pos / 4)
	{
		case 0: // red to yellow
			r = 255;
			g = steps[pos % 4];
			break;
		case 1: // yellow to green
			r = steps[3 - pos % 4];
			g = 255;
			break;
		case 2: // green to cyan
			g = 255;
			b = steps[pos % 4];
			break;
		case 3: // cyan to blue
			b = 255;
			g = steps[3 - pos % 4];
			break;
		case 4: // blue to magenta
			r = steps[pos % 4];
			b = 255;
			break;
		case 5: // magenta to red
			r = 255;
			b = steps[3 - pos % 4];
			break;
	}
	return to_string(r) + ";" + to_string(g) + ";" + to_string(b);
}

int main(int argc, char *argv[])
{
	char ch;
	int i = 0;
	int prevLineIndex = -1;
	while (stream.get(ch))
	{
		if (ch == '\n')
		{
			i = prevLineIndex;
			prevLineIndex++;
			if (prevLineIndex == 23)
				prevLineIndex = -1;
		}
		i++;
		if (i == 24)
			i = 0;
		cout << "\x1b[38;2;" << test(i) << 'm';
		cout << ch;
	}
	// Reset to default colors
	cout << "\x1b[0m";
	return 0;
}

