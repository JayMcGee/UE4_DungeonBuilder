// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "DungeonBuilderPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDungeonBuilderPlayerController() {}
// Cross Module References
	DUNGEONBUILDER_API UClass* Z_Construct_UClass_ADungeonBuilderPlayerController_NoRegister();
	DUNGEONBUILDER_API UClass* Z_Construct_UClass_ADungeonBuilderPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_DungeonBuilder();
// End Cross Module References
	void ADungeonBuilderPlayerController::StaticRegisterNativesADungeonBuilderPlayerController()
	{
	}
	UClass* Z_Construct_UClass_ADungeonBuilderPlayerController_NoRegister()
	{
		return ADungeonBuilderPlayerController::StaticClass();
	}
	UClass* Z_Construct_UClass_ADungeonBuilderPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_APlayerController,
				(UObject* (*)())Z_Construct_UPackage__Script_DungeonBuilder,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "DungeonBuilderPlayerController.h" },
				{ "ModuleRelativePath", "DungeonBuilderPlayerController.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ADungeonBuilderPlayerController>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ADungeonBuilderPlayerController::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00800284u,
				nullptr, 0,
				nullptr, 0,
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADungeonBuilderPlayerController, 3219646410);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADungeonBuilderPlayerController(Z_Construct_UClass_ADungeonBuilderPlayerController, &ADungeonBuilderPlayerController::StaticClass, TEXT("/Script/DungeonBuilder"), TEXT("ADungeonBuilderPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADungeonBuilderPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
