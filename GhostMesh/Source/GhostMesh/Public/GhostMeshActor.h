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

#include "GameFramework/Actor.h"
#include "CustomPoseableMeshComponent.h"
#include "GhostMeshActor.generated.h"

UCLASS()
class GHOSTMESH_API AGhostMeshActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGhostMeshActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	/** Cable component that performs simulation and rendering */
	UPROPERTY(Category = Ghost, VisibleAnywhere, BlueprintReadWrite)
	class UCustomPoseableMeshComponent* GhostMesh;


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Pose Mesh Actor", Keywords = "skeletal Pose"), Category = "GhostMesh|Mesh")
	bool MakePoseBySkeletalMesh(USkeletalMeshComponent* SkeletalMeshComp);


	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Spawned"))
	void OnSpawned();
};
