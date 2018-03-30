// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "DungeonBuilderGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDungeonBuilderGameMode() {}
// Cross Module References
	DUNGEONBUILDER_API UClass* Z_Construct_UClass_ADungeonBuilderGameMode_NoRegister();
	DUNGEONBUILDER_API UClass* Z_Construct_UClass_ADungeonBuilderGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_DungeonBuilder();
// End Cross Module References
	void ADungeonBuilderGameMode::StaticRegisterNativesADungeonBuilderGameMode()
	{
	}
	UClass* Z_Construct_UClass_ADungeonBuilderGameMode_NoRegister()
	{
		return ADungeonBuilderGameMode::StaticClass();
	}
	UClass* Z_Construct_UClass_ADungeonBuilderGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_DungeonBuilder,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "DungeonBuilderGameMode.h" },
				{ "ModuleRelativePath", "DungeonBuilderGameMode.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ADungeonBuilderGameMode>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ADungeonBuilderGameMode::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00880288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADungeonBuilderGameMode, 2902156261);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADungeonBuilderGameMode(Z_Construct_UClass_ADungeonBuilderGameMode, &ADungeonBuilderGameMode::StaticClass, TEXT("/Script/DungeonBuilder"), TEXT("ADungeonBuilderGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADungeonBuilderGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
