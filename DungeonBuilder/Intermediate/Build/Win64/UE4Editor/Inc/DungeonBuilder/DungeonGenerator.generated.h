// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DUNGEONBUILDER_DungeonGenerator_generated_h
#error "DungeonGenerator.generated.h already included, missing '#pragma once' in DungeonGenerator.h"
#endif
#define DUNGEONBUILDER_DungeonGenerator_generated_h

#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_RPC_WRAPPERS
#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADungeonGenerator(); \
	friend DUNGEONBUILDER_API class UClass* Z_Construct_UClass_ADungeonGenerator(); \
public: \
	DECLARE_CLASS(ADungeonGenerator, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DungeonBuilder"), NO_API) \
	DECLARE_SERIALIZER(ADungeonGenerator) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADungeonGenerator(); \
	friend DUNGEONBUILDER_API class UClass* Z_Construct_UClass_ADungeonGenerator(); \
public: \
	DECLARE_CLASS(ADungeonGenerator, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DungeonBuilder"), NO_API) \
	DECLARE_SERIALIZER(ADungeonGenerator) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADungeonGenerator(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADungeonGenerator) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADungeonGenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADungeonGenerator); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADungeonGenerator(ADungeonGenerator&&); \
	NO_API ADungeonGenerator(const ADungeonGenerator&); \
public:


#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADungeonGenerator(ADungeonGenerator&&); \
	NO_API ADungeonGenerator(const ADungeonGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADungeonGenerator); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADungeonGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADungeonGenerator)


#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_PRIVATE_PROPERTY_OFFSET
#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_9_PROLOG
#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_PRIVATE_PROPERTY_OFFSET \
	DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_RPC_WRAPPERS \
	DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_INCLASS \
	DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_PRIVATE_PROPERTY_OFFSET \
	DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_INCLASS_NO_PURE_DECLS \
	DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DungeonBuilder_Source_DungeonBuilder_DungeonGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
