#include <stdio.h>

#include <ccVector/ccVector.h>

#define PI 3.141592f

static void printVec3(ccVec3 v) {
	unsigned int i;

	for(i = 0; i < 3; i++) {
		printf("%.2f\n", v.v[i]);
	}
	printf("\n");
}

static void printMat3x3(ccMat3x3 m) {
	unsigned int c, r;

	for(c = 0; c < 3; c++) {
		for(r = 0; r < 3; r++) {
			printf("%.2f\t", m[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char **argv) {
	ccVec3 vector, vectorMultiplied;
	ccVec2 add;
	ccMat3x3 transform;

	vector.x = 3;
	vector.y = 0;
	vector.z = 1;

	add.x = 1000;
	add.y = 1000;

	printVec3(vector);

	vectorMultiplied = vector;

	ccMat3x3Identity(transform);
	ccMat3x3Rotate2D(transform, PI / 4);
	ccMat3x3Scale2D(transform, 2);
	ccMat3x3Translate(transform, add);

	printMat3x3(transform);

	printVec3(ccMat3x3GetCol(transform, 1));

	printf("Applying transformation matrix...\n\n");

	vectorMultiplied = ccMat3x3MultiplyVector(transform, vector);

	printVec3(vectorMultiplied);

	printf("Length: %.2f\n", ccVec2Length(vector.vec2));

	return 0;
}