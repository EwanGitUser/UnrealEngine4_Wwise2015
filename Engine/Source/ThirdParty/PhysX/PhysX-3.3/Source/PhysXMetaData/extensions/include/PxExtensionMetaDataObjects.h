/*
 * Copyright (c) 2008-2015, NVIDIA CORPORATION.  All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */
// Copyright (c) 2004-2008 AGEIA Technologies, Inc. All rights reserved.
// Copyright (c) 2001-2004 NovodeX AG. All rights reserved.

#ifndef PX_EXTENSION_METADATAOBJECTS_H
#define PX_EXTENSION_METADATAOBJECTS_H
#include "PxPhysicsAPI.h"
#include "extensions/PxExtensionsAPI.h"
#include "PxMetaDataObjects.h"

/** \addtogroup physics
@{
*/

namespace physx
{

class PxD6Joint;
class PxJointLimitPair;
class PxJointLimitCone;

struct PxExtensionsPropertyInfoName
{
	enum Enum
	{
		Unnamed = PxPropertyInfoName::LastPxPropertyInfoName,
#include "PxExtensionAutoGeneratedMetaDataObjectNames.h"
		LastPxPropertyInfoName
	};
};

#define DEFINE_PROPERTY_TO_VALUE_STRUCT_MAP( type, prop, valueStruct )																	\
	template<> struct PxPropertyToValueStructMemberMap< PxExtensionsPropertyInfoName::type##_##prop >									\
	{																																	\
		PxU32 Offset;																													\
		PxPropertyToValueStructMemberMap< PxExtensionsPropertyInfoName::type##_##prop >() : Offset( offsetof( valueStruct, prop ) ) {}	\
		template<typename TOperator> void visitProp( TOperator inOperator, valueStruct& inStruct ) { inOperator( inStruct.prop );	}	\
	};

#include "PxExtensionAutoGeneratedMetaDataObjects.h"

#undef DEFINE_PROPERTY_TO_VALUE_STRUCT_MAP

}

/** @} */
#endif
