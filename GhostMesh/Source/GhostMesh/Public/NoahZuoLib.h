////////////////////////////////////////////////////////////
//
// Copyright (C) 2016 Noah Zuo (noahzuo1994@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////
#pragma once

//#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"
#include "NoahZuoLib.generated.h"

/**
 * My Function Library
 */
UCLASS()
class GHOSTMESH_API UNoahZuoLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Skeletal Bone nums", Keywords = "skeletal bone num"), Category = "NoahFunction|Skeletal")
	static int32 GetSkeletalBoneNum(USkeletalMesh* SkeletalMesh);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Skeletal Bone names", Keywords = "skeletal bone name"), Category = "NoahFunction|Skeletal")
	static TArray<FName> GetSkeletalBoneNames(USkeletalMesh* SkeletalMesh);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Skeletal Pose", Keywords = "skeletal bone pose"), Category = "NoahFunction|Skeletal")
	static TArray<FTransform> GetSkeletalPose(USkeletalMesh* SkeletalMesh);
	
	
};
