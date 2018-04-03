// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "DungeonGenerator.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDungeonGenerator() {}
// Cross Module References
	DUNGEONBUILDER_API UScriptStruct* Z_Construct_UScriptStruct_FRoom();
	UPackage* Z_Construct_UPackage__Script_DungeonBuilder();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	DUNGEONBUILDER_API UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister();
	DUNGEONBUILDER_API UClass* Z_Construct_UClass_ADungeonGenerator();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
class UScriptStruct* FRoom::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern DUNGEONBUILDER_API uint32 Get_Z_Construct_UScriptStruct_FRoom_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FRoom, Z_Construct_UPackage__Script_DungeonBuilder(), TEXT("Room"), sizeof(FRoom), Get_Z_Construct_UScriptStruct_FRoom_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FRoom(FRoom::StaticStruct, TEXT("/Script/DungeonBuilder"), TEXT("Room"), false, nullptr, nullptr);
static struct FScriptStruct_DungeonBuilder_StaticRegisterNativesFRoom
{
	FScriptStruct_DungeonBuilder_StaticRegisterNativesFRoom()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("Room")),new UScriptStruct::TCppStructOps<FRoom>);
	}
} ScriptStruct_DungeonBuilder_StaticRegisterNativesFRoom;
	UScriptStruct* Z_Construct_UScriptStruct_FRoom()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FRoom_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_DungeonBuilder();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("Room"), sizeof(FRoom), Get_Z_Construct_UScriptStruct_FRoom_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "ModuleRelativePath", "DungeonGenerator.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRoom>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsMain_MetaData[] = {
				{ "ModuleRelativePath", "DungeonGenerator.h" },
			};
#endif
			auto NewProp_bIsMain_SetBit = [](void* Obj){ ((FRoom*)Obj)->bIsMain = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsMain = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsMain", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FRoom), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bIsMain_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bIsMain_MetaData, ARRAY_COUNT(NewProp_bIsMain_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RoomWidth_MetaData[] = {
				{ "ModuleRelativePath", "DungeonGenerator.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RoomWidth = { UE4CodeGen_Private::EPropertyClass::Float, "RoomWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FRoom, RoomWidth), METADATA_PARAMS(NewProp_RoomWidth_MetaData, ARRAY_COUNT(NewProp_RoomWidth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RoomLength_MetaData[] = {
				{ "ModuleRelativePath", "DungeonGenerator.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RoomLength = { UE4CodeGen_Private::EPropertyClass::Float, "RoomLength", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FRoom, RoomLength), METADATA_PARAMS(NewProp_RoomLength_MetaData, ARRAY_COUNT(NewProp_RoomLength_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Coordinates_MetaData[] = {
				{ "ModuleRelativePath", "DungeonGenerator.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Coordinates = { UE4CodeGen_Private::EPropertyClass::Struct, "Coordinates", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FRoom, Coordinates), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(NewProp_Coordinates_MetaData, ARRAY_COUNT(NewProp_Coordinates_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RoomId_MetaData[] = {
				{ "ModuleRelativePath", "DungeonGenerator.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_RoomId = { UE4CodeGen_Private::EPropertyClass::Struct, "RoomId", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FRoom, RoomId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(NewProp_RoomId_MetaData, ARRAY_COUNT(NewProp_RoomId_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bIsMain,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RoomWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RoomLength,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Coordinates,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RoomId,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_DungeonBuilder,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"Room",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FRoom),
				alignof(FRoom),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FRoom_CRC() { return 3563205023U; }
	void ADungeonGenerator::StaticRegisterNativesADungeonGenerator()
	{
	}
	UClass* Z_Construct_UClass_ADungeonGenerator_NoRegister()
	{
		return ADungeonGenerator::StaticClass();
	}
	UClass* Z_Construct_UClass_ADungeonGenerator()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_DungeonBuilder,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "DungeonGenerator.h" },
				{ "ModuleRelativePath", "DungeonGenerator.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratorGridSize_MetaData[] = {
				{ "Category", "Dungeon Generator" },
				{ "ModuleRelativePath", "DungeonGenerator.h" },
				{ "ToolTip", "The Maximum Length of a room" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GeneratorGridSize = { UE4CodeGen_Private::EPropertyClass::Float, "GeneratorGridSize", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADungeonGenerator, GeneratorGridSize), METADATA_PARAMS(NewProp_GeneratorGridSize_MetaData, ARRAY_COUNT(NewProp_GeneratorGridSize_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaximumRoomLength_MetaData[] = {
				{ "Category", "Dungeon Generator" },
				{ "ModuleRelativePath", "DungeonGenerator.h" },
				{ "ToolTip", "The Maximum Length of a room" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaximumRoomLength = { UE4CodeGen_Private::EPropertyClass::Float, "MaximumRoomLength", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADungeonGenerator, MaximumRoomLength), METADATA_PARAMS(NewProp_MaximumRoomLength_MetaData, ARRAY_COUNT(NewProp_MaximumRoomLength_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinimumRoomLength_MetaData[] = {
				{ "Category", "Dungeon Generator" },
				{ "ModuleRelativePath", "DungeonGenerator.h" },
				{ "ToolTip", "The Minimum Length of a room" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinimumRoomLength = { UE4CodeGen_Private::EPropertyClass::Float, "MinimumRoomLength", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADungeonGenerator, MinimumRoomLength), METADATA_PARAMS(NewProp_MinimumRoomLength_MetaData, ARRAY_COUNT(NewProp_MinimumRoomLength_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaximumRoomWidth_MetaData[] = {
				{ "Category", "Dungeon Generator" },
				{ "ModuleRelativePath", "DungeonGenerator.h" },
				{ "ToolTip", "The Maximum Width of a room" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaximumRoomWidth = { UE4CodeGen_Private::EPropertyClass::Float, "MaximumRoomWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADungeonGenerator, MaximumRoomWidth), METADATA_PARAMS(NewProp_MaximumRoomWidth_MetaData, ARRAY_COUNT(NewProp_MaximumRoomWidth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinimumRoomWidth_MetaData[] = {
				{ "Category", "Dungeon Generator" },
				{ "ModuleRelativePath", "DungeonGenerator.h" },
				{ "ToolTip", "The Minimum Width of a room" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinimumRoomWidth = { UE4CodeGen_Private::EPropertyClass::Float, "MinimumRoomWidth", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADungeonGenerator, MinimumRoomWidth), METADATA_PARAMS(NewProp_MinimumRoomWidth_MetaData, ARRAY_COUNT(NewProp_MinimumRoomWidth_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NumberOfRooms_MetaData[] = {
				{ "Category", "Dungeon Generator" },
				{ "ModuleRelativePath", "DungeonGenerator.h" },
				{ "ToolTip", "The Number of rooms to be generated" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NumberOfRooms = { UE4CodeGen_Private::EPropertyClass::Float, "NumberOfRooms", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADungeonGenerator, NumberOfRooms), METADATA_PARAMS(NewProp_NumberOfRooms_MetaData, ARRAY_COUNT(NewProp_NumberOfRooms_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneratorCircleRadius_MetaData[] = {
				{ "Category", "Dungeon Generator" },
				{ "ModuleRelativePath", "DungeonGenerator.h" },
				{ "ToolTip", "The radius of the circle the rooms will initially be spawned" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GeneratorCircleRadius = { UE4CodeGen_Private::EPropertyClass::Float, "GeneratorCircleRadius", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ADungeonGenerator, GeneratorCircleRadius), METADATA_PARAMS(NewProp_GeneratorCircleRadius_MetaData, ARRAY_COUNT(NewProp_GeneratorCircleRadius_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GeneratorGridSize,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaximumRoomLength,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MinimumRoomLength,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaximumRoomWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MinimumRoomWidth,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_NumberOfRooms,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GeneratorCircleRadius,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ADungeonGenerator>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ADungeonGenerator::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADungeonGenerator, 2343710628);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADungeonGenerator(Z_Construct_UClass_ADungeonGenerator, &ADungeonGenerator::StaticClass, TEXT("/Script/DungeonBuilder"), TEXT("ADungeonGenerator"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADungeonGenerator);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
