// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DUNGEONBUILDER_DungeonBuilderCharacter_generated_h
#error "DungeonBuilderCharacter.generated.h already included, missing '#pragma once' in DungeonBuilderCharacter.h"
#endif
#define DUNGEONBUILDER_DungeonBuilderCharacter_generated_h

#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_RPC_WRAPPERS
#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADungeonBuilderCharacter(); \
	friend DUNGEONBUILDER_API class UClass* Z_Construct_UClass_ADungeonBuilderCharacter(); \
public: \
	DECLARE_CLASS(ADungeonBuilderCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DungeonBuilder"), NO_API) \
	DECLARE_SERIALIZER(ADungeonBuilderCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADungeonBuilderCharacter(); \
	friend DUNGEONBUILDER_API class UClass* Z_Construct_UClass_ADungeonBuilderCharacter(); \
public: \
	DECLARE_CLASS(ADungeonBuilderCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DungeonBuilder"), NO_API) \
	DECLARE_SERIALIZER(ADungeonBuilderCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADungeonBuilderCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADungeonBuilderCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADungeonBuilderCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADungeonBuilderCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADungeonBuilderCharacter(ADungeonBuilderCharacter&&); \
	NO_API ADungeonBuilderCharacter(const ADungeonBuilderCharacter&); \
public:


#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADungeonBuilderCharacter(ADungeonBuilderCharacter&&); \
	NO_API ADungeonBuilderCharacter(const ADungeonBuilderCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADungeonBuilderCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADungeonBuilderCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADungeonBuilderCharacter)


#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TopDownCameraComponent() { return STRUCT_OFFSET(ADungeonBuilderCharacter, TopDownCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ADungeonBuilderCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__CursorToWorld() { return STRUCT_OFFSET(ADungeonBuilderCharacter, CursorToWorld); }


#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_9_PROLOG
#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_RPC_WRAPPERS \
	DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_INCLASS \
	DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_INCLASS_NO_PURE_DECLS \
	DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID DungeonBuilder_Source_DungeonBuilder_DungeonBuilderCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
