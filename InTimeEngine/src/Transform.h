/******************************************************************************
 * Copyright (c) 2024 Christopher Barrios Agosto. All Rights Reserved.
 *
 * Licensing Information:
 *  This software and associated documentation files (the "Software") may not
 *  be used, copied, modified, merged, published, distributed, sublicensed,
 *  or sold without the prior written permission of the copyright owner.
 *
 *  Unauthorized use of this file, via any medium, is strictly prohibited.
 *****************************************************************************/

/******************************************************************************
 * Project: In Time Engine
 * File: Transform.h
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 * Updated on: 13DEC2024
 *
 * Description:
 *  Owned through "has a" relationship by the GameObject class.
 *  This is the means to control game objects three dimensional behaviour
 *  (translation, rotation (euler & quaternion) and scale).
 *  Parent and child transforms can be assigned.
 *  Parent and child relationships are automatically broken through
 *  destructor.
 *  Game objects's transform will live even after the destroy or
 *  destroyImmediately are called if stack allocated until the game object's
 *  destructro is called.
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <vector>
#include <functional>

// Dependencies | std
#include <list>

// Dependencies | glm
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace IT {
	// Forward declarations
	class GameObject;
	class Transform;
	class ITransform;

	class ITransform {
		// Friends
		friend class Transform;

		// Object
		private:
			// Properties
			std::list<ITransform*>* listPointer = nullptr;
			std::list<ITransform*>::iterator node;

		public:
			// Constructor / Destructor
			ITransform();
			~ITransform();

			// Functions
			virtual void onTransformChange();
	};

	class Transform {
		// Friends
		friend class SceneLoader;

		// Object
		private:
			// Properties
			GameObject& gameObject;
			Transform* parent;
			std::vector<Transform*> children;
			std::list<ITransform*> listeners;
			std::list<Transform*>::iterator gpuUpdateNode;

		public:
			// Properties
			glm::vec3 position = glm::vec3(0, 0, 0);
			glm::vec3 rotation = glm::vec3(0, 0, 0);
			glm::vec3 scale = glm::vec3(1, 1, 1);
			glm::quat orientation = glm::quat(1, 0, 0, 0);
			glm::mat4 globalMatrix = glm::mat4(1);
			bool requiresUpdate = true;

			// Constructor / Destructor
			Transform(GameObject& gameObject);
			~Transform();

			// Getters
			GameObject& getGameObject() const;
			glm::vec3 getPosition() const;
			glm::vec3 getRotation() const;
			glm::vec3 getScale() const;
			glm::quat getOrientation() const;
			glm::mat4 getGlobalMatrix();
			bool getRequiresUpdate() const;
			Transform* getParent() const;
			std::vector<Transform*> getChildren() const;

			// Setters
			void setPosition(const glm::vec3& position);
			void setRotation(const glm::vec3& rotation);
			void setScale(const glm::vec3& scale);
			void setOrientation(const glm::quat& orientation);
			void setRequiresUpdate(bool requiresUpdate);
			void setParent(Transform* transform);

			// Functions
			void translateBy(const glm::vec3& translation);
			void rotateBy(const glm::vec3& rotation);
			void scaleBy(const glm::vec3& scale);
			void setLocalMatrix(const glm::mat4& globalMatrix);
			glm::mat4 getMatrix() const;

			void calculateGlobalMatrix();
			glm::vec3 getGlobalPosition();
			glm::vec3 getGlobalRotation() const;
			glm::vec3 getGlobalScale() const;
			glm::quat getGlobalOrientation() const;

			// ITransform | Functions
			void addListener(ITransform* iTransform);
			void removeListener(ITransform* iTransform);
	};
}
