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
#include "GhostMeshActor.h"


// Sets default values
AGhostMeshActor::AGhostMeshActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	GhostMesh = CreateDefaultSubobject<UCustomPoseableMeshComponent>(TEXT("Ghost000"));
	GhostMesh->SetAbsolute(false, false, false);
}

// Called when the game starts or when spawned
void AGhostMeshActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGhostMeshActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool AGhostMeshActor::MakePoseBySkeletalMesh(USkeletalMeshComponent* SkeletalMesh)
{
	auto skelton = SkeletalMesh->SkeletalMesh;
	if (!IsValid(skelton))
	{
		return false;
	}

	auto compTransform = SkeletalMesh->GetComponentTransform();
	GhostMesh->SetSkeletalMesh(skelton);
	OnSpawned();
	GhostMesh->SetWorldTransform(compTransform);
	GhostMesh->MakePoseBySkeletalMesh(SkeletalMesh);
	return true;
}