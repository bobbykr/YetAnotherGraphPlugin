#include "BinarySelectNode.h"
#include "Logger.h"
#include "YAGraph.h"

#define LOCTEXT_NAMESPACE "UYANode"

UBinarySelectNode::UBinarySelectNode()
{
    DefaultNodeTitle = LOCTEXT("BinarySelectNode", "Binary Select");
}



UYANode * UBinarySelectNode::GetNodePointer_Implementation()
{
    if (ChildNodes.Num() == 1) return BooleanEvaluation() ? ChildNodes[0] : nullptr;
    if (ChildNodes.Num() == 2) return BooleanEvaluation() ? ChildNodes[0] : ChildNodes[1];
    ELog("There are %d subnode on a binary select node.", ChildNodes.Num());
    return nullptr;
}


#undef LOCTEXT_NAMESPACE