// GeneticProgramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<random>
#include<math.h>
#include "GeneticSequence.h"

void GeneticSequence::InputGeneData()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter the Gene Data According to the Key Provided." << endl;
	cout << "1 -> Adenine" << endl << "2 -> Guanine" << endl << "3 -> Cytosine" << endl << "4 -> Thiamine" << endl;
	cout << "Enter the Data of Gene 1" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> NodeData1[i][j];
		}
	}
	cout << "Enter the Data of Gene 2" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> NodeData2[i][j];
		}
	}
	cout << "GENE_DATA_I \t\tGENE_DATA_II" << endl << endl;
	RecombineGeneDat();
}
void GeneticSequence::RecombineGeneDat()
{
	double bittemp = 0.0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bittemp = (NodeData1[i][j] + NodeData2[i][j]) / 2;
			GeneratedNodeData[i][j] = GenerateRandom(floor(bittemp), ceil(bittemp));
		}
	}
	ProduceGene();
}
void GeneticSequence::ProduceGene() 
{
	using std::cout;
	using std::endl;
	
	//Print the Sequence of DNA Data 1
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			GetGeneComponent(NodeData1[i][j]);
		}
		cout << "\t\t";
		for (int j = 0; j < 4; j++)
		{
			GetGeneComponent(NodeData2[i][j]);
		}
		cout << endl;
	}

	cout << "The Genes above have been recombined. " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "\t\t";
			GetGeneComponent(GeneratedNodeData[i][j]);
		}
		cout << endl;
		
	}
}

void GeneticSequence::GetGeneComponent(int G_COMP_DAT)
{
	switch (G_COMP_DAT)
	{
	case AD:
		std::cout << "AD ";
		break;
	case GU:
		std::cout << "GU ";
		break;
	case CY:
		std::cout << "CY ";
		break;
	case TH:
		std::cout << "TH ";
		break;
	}
}
int GeneticSequence::GenerateRandom(int st, int en)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(st, en);

	return(dist6(rng));
}

int main()
{
	GeneticSequence GSequence = GeneticSequence();
	GSequence.InputGeneData();
	return 0;
}




