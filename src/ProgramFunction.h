/*******************************************************************************************************************************
This file is a part of the EvoDesign physical Energy Function (EvoEF)

Copyright (c) 2019 Xiaoqiang Huang (tommyhuangthu@foxmail.com, xiaoqiah@umich.edu)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation 
files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, 
modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
********************************************************************************************************************************/

#ifndef PROGRAM_FUNCTION_H
#define PROGRAM_FUNCTION_H

#include "Structure.h"
#include "EnergyFunction.h"


int NOVA_help();
int NOVA_version();
int NOVA_interface();
int NOVA_ComputeChainStability(Structure *pStructure, int chainIndex, double *energyTerms);
int NOVA_ComputeStability(Structure *pStructure,AAppTable* pAAppTable,RamaTable* pRama,double energyTerms[MAX_EVOEF_ENERGY_TERM_NUM]);
int NOVA_ComputeStabilityWithBBdepRotLib(Structure *pStructure,AAppTable* pAAppTable,RamaTable* pRama,BBdepRotamerLib* pRotLib,double energyTerms[MAX_EVOEF_ENERGY_TERM_NUM]);
int NOVA_ComputeStabilityForSelectedChains(Structure *pStructure, double *energyTerms,char selechains[]);
int NOVA_ComputeBinding(Structure *pStructure);
int NOVA_ComputeBindingWithSplitting(Structure *pStructure,char split1[], char split2[]);
int NOVA_ComputeBindingWithSplittingNew(Structure *pStructure,char split1[], char split2[]);
int NOVA_BuildMutant(Structure* pStructure, char* mutantfile, BBindRotamerLib* rotlib, AtomParamsSet* atomParams,ResiTopoSet* resiTopos, char* pdbid);
int NOVA_BuildMutantWithBBdepRotLib(Structure* pStructure, char* mutantfile, BBdepRotamerLib* pBBdepRotLib, AtomParamsSet* atomParams,ResiTopoSet* resiTopos, char* pdbid);
int NOVA_RepairStructure(Structure* pStructure, BBindRotamerLib* rotlib, AtomParamsSet* atomParams,ResiTopoSet* resiTopos, char* pdbid);
int NOVA_WriteStructureToFile(Structure* pStructure, char* pdbfile);
int NOVA_AddHydrogen(Structure* pStructure, char* pdbid);
int NOVA_OptimizeHydrogen(Structure* pStructure, AtomParamsSet* atomParams,ResiTopoSet* resiTopos, char* pdbid);
int NOVA_StructureComputeResidueInteractionWithFixedSurroundingResidues(Structure *pStructure, int chainIndex, int residueIndex);


int NOVA_ComputeRotamersEnergy(Structure* pStructure,BBindRotamerLib* rotlib,AAppTable* pAAppTable,RamaTable* pRama,AtomParamsSet* atomParams,ResiTopoSet* resiTopos,char* pdbid);
int NOVA_ComputeWildtypeRotamersEnergy(Structure* pStructure,BBindRotamerLib* rotlib,AAppTable* pAAppTable,RamaTable* pRama,AtomParamsSet* atomParams,ResiTopoSet* resiTopos, char* pdbid);

int NOVA_StructureFindInterfaceResidues(Structure *pStructure,double cutoff,char* outputfile);
int StructureCalcPhiPsi(Structure* pStructure);
int NOVA_StructureShowPhiPsi(Structure* pStructure,char* phipsifile);
int NOVA_ComputeRotamersEnergyByBBdepRotLib(Structure* pStructure,BBdepRotamerLib* rotlib,AAppTable* pAAppTable,RamaTable* pRama,AtomParamsSet* atomParams,ResiTopoSet* resiTopos,char* pdbid);
int NOVA_ComputeWildtypeRotamersEnergyByBBdepRotLib(Structure* pStructure,BBdepRotamerLib* rotlib,AAppTable* pAAppTable,RamaTable* pRama,AtomParamsSet* atomParams,ResiTopoSet* resiTopos,char* pdbid);

int NOVA_CheckRotamerInBBindRotLib(Structure* pStructure,BBindRotamerLib* pRotLib,ResiTopoSet* pTopos,double cutoff,char* pdbid);
int NOVA_CheckRotamerInBBdepRotLib(Structure* pStructure,BBdepRotamerLib* pRotLib,ResiTopoSet* pTopos,double cutoff,char* pdbid);
int NOVA_RepairStructureWithBBdepRotLib(Structure* pStructure, BBdepRotamerLib* pBBdepRotLib, AtomParamsSet* atomParams,ResiTopoSet* resiTopos,char* pdbid);
int NOVA_GetResiMinRmsdRotFromLab(Structure* pStructure,char* pdbid);



#endif //PROGRAM_FUNCTION_H