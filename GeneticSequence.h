#pragma once
#include<iostream>
#ifndef _GENETIC_SEQUENCE
#define _GENETIC_SEQUENCE

class GeneticSequence
{
private:
	enum GeneData
	{
		AD = 1,
		GU = 2,
		CY = 3,
		TH = 4
	};
	int NODEL;
	static const int M = 5;
	static const int N = 4;
	int NodeData1[M][N];
	int NodeData2[M][N];
	int GeneratedNodeData[5][4];
	
public:
	void InputGeneData();
	void RecombineGeneDat();
	void ProduceGene();
	void GetGeneComponent(int G_COMP_DAT);
	int GenerateRandom(int st, int en);
};

#endif // !_GENETIC_SEQUENCE



