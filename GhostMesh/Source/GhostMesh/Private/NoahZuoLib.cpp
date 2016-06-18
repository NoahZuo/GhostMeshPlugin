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
#include "GhostMeshPrivatePCH.h"

#include "NoahZuoLib.h"




int32 UNoahZuoLib::GetSkeletalBoneNum(USkeletalMesh* SkeletalMesh)
{
	if (!IsValid(SkeletalMesh))
	{
		return -1;
	}

	auto Skeleton = SkeletalMesh->RefSkeleton;


	return Skeleton.GetNum();
}


TArray<FName> UNoahZuoLib::GetSkeletalBoneNames(USkeletalMesh* SkeletalMesh)
{
	TArray<FName> Result;

	if (!IsValid(SkeletalMesh))
	{
		return Result;
	}


	auto boneNum = GetSkeletalBoneNum(SkeletalMesh);
	auto skel = SkeletalMesh->RefSkeleton;

	auto boneinfo = skel.GetRefBoneInfo();
	for (int i = 0; i < boneNum; i++)
	{
		FName tmp = boneinfo[i].Name;

		Result.Add(tmp);
	}

	return Result;
}

TArray<FTransform> UNoahZuoLib::GetSkeletalPose(USkeletalMesh* SkeletalMesh)
{

	TArray<FTransform> Result;

	if (!IsValid(SkeletalMesh))
	{
		return Result;
	}

	return SkeletalMesh->RefSkeleton.GetRefBonePose();
}