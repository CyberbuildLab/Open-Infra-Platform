/*
    This file is part of Expresso, a simple early binding generator for EXPRESS.
	Copyright (c) 2016 Technical University of Munich
	Chair of Computational Modeling and Simulation.

    BlueFramework is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License Version 3
    as published by the Free Software Foundation.

    BlueFramework is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#pragma once
#ifndef OpenInfraPlatform_EarlyBinding_EXPRESSReference_c5a3045b_df30_4a77_aeea_3a16cde5c141_h
#define OpenInfraPlatform_EarlyBinding_EXPRESSReference_c5a3045b_df30_4a77_aeea_3a16cde5c141_h

#include "../EarlyBinding/src/namespace.h"

#include "EXPRESSEntity.h"
#include "EXPRESSModel.h"

#include <memory>
#include <string>
#include <utility>

OIP_NAMESPACE_OPENINFRAPLATFORM_EARLYBINDING_BEGIN

template <typename T> class EXPRESSReference : public std::weak_ptr<T> {
	//static_assert(std::is_base_of<EXPRESSEntity, T>::value, "EXPRESSReference can only be specialized with class derived from EXPRESSEntity");
	using base = std::weak_ptr<T>;
public:
	typedef base UnderlyingType;

	EXPRESSReference() = default;
	EXPRESSReference(const EXPRESSReference& other) = default;
	~EXPRESSReference() { 
		this->base::reset();
		this->model.reset();
	}

	using base::base;
	using base::operator=;

	auto lock() -> decltype(this->base::lock()) {
		if (!this->expired() && refId != 0) {
			return this->base::lock();
		}
		else if (this->base::expired() && !model.expired() && refId != 0 && model.lock()->entities.count(refId) > 0) {
			this->base::operator=(std::dynamic_pointer_cast<T>(model.lock()->entities[refId]));
			return this->base::lock();
		}
		else {
			return this->base::lock();
		}
	}


	const std::string getStepParameter() const;
	

	T* operator->() { return this->lock().operator->(); }
	const T* const operator->() const { return this->base::lock().operator->(); }

	operator const bool() const { 
		return this->base::lock().operator bool();
	}

	operator const bool() {
		return this->lock().operator bool();
	}

	static EXPRESSReference<T> readStepData(const std::string arg, const std::shared_ptr<EXPRESSModel>& model) {
		if (arg == "*") {
			//TODO
			return EXPRESSReference<T>();
		}
		else {
			size_t refId = std::stoull(arg.substr(1, arg.size() - 1));
			EXPRESSReference<T> reference;
			if (model->entities.count(refId) > 0) {
				reference.base::operator=(std::dynamic_pointer_cast<T>(model->entities[refId]));
			}
			reference.refId = refId;
			reference.model = model;
			return reference;
		}
	}

	const std::string classname() const;
	

	friend void swap(EXPRESSReference& first, EXPRESSReference& second)
	{
		first.base::swap(second);
		std::swap(first.refId, second.refId);
		std::swap(first.model, second.model);
	}

private:
	size_t refId = 0;
	std::weak_ptr<EXPRESSModel> model;
};

OIP_NAMESPACE_OPENINFRAPLATFORM_EARLYBINDING_END

template<typename T> using EXPRESSReference = OpenInfraPlatform::EarlyBinding::EXPRESSReference<T>;
#endif // end define OpenInfraPlatform_EarlyBinding_EXPRESSReference_c5a3045b_df30_4a77_aeea_3a16cde5c141_h