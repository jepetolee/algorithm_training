// Divide & Conquer Strassen Algorithm
/*made by Volker Strassen*/
 /* O(n^0.2807....) */

#include <stdc++.h>

using namespace std;

void SumMatrix(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, vector<vector<int>>& matrixC) {
	for (int i = 0; i < matrixA.size(); i++) 
		for (int j = 0; j < matrixB.size(); j++) 
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
}
void SubMatrix(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, vector<vector<int>>& matrixC) {
	for (int i = 0; i < matrixA.size(); i++)
		for (int j = 0; j < matrixB.size(); j++)
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
}
void MultMatrix(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, vector<vector<int>>& matrixC) {
	for (int i = 0; i < matrixA.size(); i++)
		for (int j = 0; j < matrixB.size(); j++)
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
}
void DivideMatrix(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, vector<vector<int>>& matrixC) {
	for (int i = 0; i < matrixA.size(); i++)
		for (int j = 0; j < matrixB.size(); j++)
			matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
}
void MergeMatrix(vector<vector<int>>& Originalmatrix,vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, vector<vector<int>>& matrix3, vector<vector<int>>& matrix4) {
	int newsize = matrix1.size();
	for (int i = 0; i < newsize; i++) 
		for (int j = 0; j < newsize; j++) {
			Originalmatrix[i][j] = matrix1[i][j];
			Originalmatrix[i][j+newsize] = matrix2[i][j];
			Originalmatrix[i + newsize][j] = matrix3[i][j];
			Originalmatrix[i + newsize][j + newsize] = matrix4[i][j];
		}
}
void AllocMatrix(vector<vector<int>>& Originalmatrix, vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, vector<vector<int>>& matrix3, vector<vector<int>>& matrix4) {
	int newsize = matrix1.size();
	for (int i = 0; i < newsize; i++)
		for (int j = 0; j < newsize; j++) {
			matrix1[i][j] = Originalmatrix[i][j];
			matrix2[i][j] = Originalmatrix[i][j + newsize];
			matrix3[i][j] = Originalmatrix[i + newsize][j];
			matrix4[i][j] = Originalmatrix[i + newsize][j + newsize];
		}
}
void Strassen(int size,vector<vector<int>>& matrixA, vector<vector<int>>& matrixB, vector<vector<int>>& matrixC) {
	if (size <= 3)
		MultMatrix(matrixA, matrixB, matrixC);
	else {
		int newRow = size / 2;
		vector<int> newCol(newRow, 0);

		vector <vector<int>> a1(newRow, newCol), a2(newRow, newCol), a3(newRow, newCol), a4(newRow, newCol);
		vector <vector<int>> b1(newRow, newCol), b2(newRow, newCol), b3(newRow, newCol), b4(newRow, newCol);

		vector <vector<int>> m1(newRow, newCol), m2(newRow, newCol), m3(newRow, newCol), m4(newRow, newCol),
			m5(newRow, newCol), m6(newRow, newCol), m7(newRow, newCol);

		vector <vector<int>> tempA(newRow, newCol), tempB(newRow, newCol);
		vector <vector<int>> c1(newRow, newCol), c2(newRow, newCol), c3(newRow, newCol), c4(newRow, newCol);

		AllocMatrix(matrixA, a1, a2, a3, a4);
		AllocMatrix(matrixB, b1, b2, b3, b4);

		SumMatrix(a1, a4, tempA);
		SumMatrix(a1, a4, tempB);
		Strassen(newRow, tempA, tempB, m1);

		SumMatrix(a3, a4, tempA);
		Strassen(newRow, tempA, b1, m2);

		SumMatrix(b2, b4, tempB);
		Strassen(newRow, a1, tempB, m3);

		SumMatrix(b3, b1, tempB);
		Strassen(newRow, a4, tempB, m4);

		SumMatrix(a1, a2, tempA);
		Strassen(newRow, tempA, b4, m5);

		SumMatrix(a3, a1, tempA);
		SumMatrix(a1, a2, tempB);
		Strassen(newRow, tempA, tempB, m6);

		SumMatrix(a2, a4, tempA);
		SumMatrix(b3, b4, tempB);
		Strassen(newRow, tempA, tempB, m7);

		SumMatrix(m1, m4, tempA);
		SumMatrix(tempA, m7, tempB);
		SubMatrix(tempB, m5, c1);

		SumMatrix(m3, m5, c2);

		SumMatrix(m2, m4, c3);

		SumMatrix(m1, m3, tempA);
		SumMatrix(tempA, m6, tempB);
		SubMatrix(tempB, m2, c4);

		MergeMatrix(matrixC, c1, c2, c3, c4);
	}
}


int main() {
	int size;
	cin >> size;
	vector<vector<int>>	A(size, vector<int>(size, 0));
	vector<vector<int>>	B(size, vector<int>(size, 0));
	vector<vector<int>>	C(size, vector<int>(size, 0));

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin>> A[i][j];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> B[i][j];

	Strassen(size, A, B, C);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}