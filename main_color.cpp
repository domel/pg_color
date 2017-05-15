#include "ColPackHeaders.h"

using namespace ColPack;
using namespace std;

#ifndef TOP_DIR
#define TOP_DIR "."
#endif

string baseDir=TOP_DIR;

int main(int argc, char ** argv)
{
	string s_InputFile; 
	s_InputFile = baseDir;
	s_InputFile += DIR_SEPARATOR; s_InputFile += "ds4.graph";
	GraphColoringInterface * g = new GraphColoringInterface(SRC_FILE, s_InputFile.c_str(), "AUTO_DETECTED");

	g->Coloring("LARGEST_FIRST", "DISTANCE_TWO");
	//g->Coloring("DYNAMIC_LARGEST_FIRST");
	//g->Coloring();

	/* 1. Check DISTANCE_TWO coloring result
	cout<<"Check DISTANCE_TWO coloring result"<<endl;
	g->CheckDistanceTwoColoring();
	*/

	//* 2. Print coloring results
	g->PrintVertexColoringMetrics();

	//* 3. Get the list of colorID of vertices
	vector<int> vi_VertexColors;
	g->GetVertexColors(vi_VertexColors);

	printf("vector of VertexColors (size %d) \n", (int)vi_VertexColors.size());
	displayVector(&vi_VertexColors[0], vi_VertexColors.size(), 1);

	//* 4. Get seed matrix
	int i_SeedRowCount = 0;
	int i_SeedColumnCount = 0;
	double** Seed = g->GetSeedMatrix(&i_SeedRowCount, &i_SeedColumnCount);

	printf("Seed matrix %d x %d \n", i_SeedRowCount, i_SeedColumnCount);
	displayMatrix(Seed, i_SeedRowCount, i_SeedColumnCount, 1);

	delete g;
	return 0;
}

