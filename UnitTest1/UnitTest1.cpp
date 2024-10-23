#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Project_7.1_rec\Project_7.1_rec\lab_7.1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2;
			int colCount = 3;
			int** testMatrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				testMatrix[i] = new int[colCount];

			// ���������� �������
			testMatrix[0][0] = -3;
			testMatrix[0][1] = 5;
			testMatrix[0][2] = -9;
			testMatrix[1][0] = -8;
			testMatrix[1][1] = 6;
			testMatrix[1][2] = -12;

			// ���� ��� ����������
			int sum = 0;
			int count = 0;

			// ��������� ������� ��� ����������
			CalcSumAndCount(testMatrix, rowCount, colCount, sum, count);

			// ������� �������� ����������
			Assert::AreEqual(-12, sum);  // ���� (-3 + -9 = -12)
			Assert::AreEqual(2, count);  // ʳ������ �������� (-3, -9)
			Assert::AreEqual(0, testMatrix[0][0]);  // �������, �� -3 ��������� �� 0
			Assert::AreEqual(5, testMatrix[0][1]);  // 5 ������� ���������� ��� ���
			Assert::AreEqual(0, testMatrix[0][2]);  // -9 ��������� �� 0
			Assert::AreEqual(-8, testMatrix[1][0]);  // -8 �� ������ �� ����� �����
			Assert::AreEqual(6, testMatrix[1][1]);   // 6 �� ���������
			Assert::AreEqual(-12, testMatrix[1][2]); // -12 �� ����������, ������� ������� �� 4

			// ��������� ���'���
			for (int i = 0; i < rowCount; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}
