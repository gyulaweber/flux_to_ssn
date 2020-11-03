#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  // Read the first argument
	float flux = atof(argv[1]);

	// Coefficients for sunspot number conversion
	float c1 = 1.61;
	float c2 = -0.00538;
	float c3 = 0.0000139;

	// Minimum expected 10.7 cm flux 
	float fluxMin = 67;

	float d = flux - fluxMin;
	float dSquared = d * d;
	float dCubed = dSquared * d;
	float ssn = c1 * d + c2 * dSquared + c3 * dCubed;
	if (ssn < 0) {
		ssn = 0;
	}

	printf("%i", (int)(ssn + 0.5));

	return 0;
}
