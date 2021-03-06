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
#ifndef OpenInfraPlatform_EarlyBinding_EXPRESSEntity_5fd9c3bc_1d26_4fef_994f_229551a1c3f8_h
#define OpenInfraPlatform_EarlyBinding_EXPRESSEntity_5fd9c3bc_1d26_4fef_994f_229551a1c3f8_h

#include "../EarlyBinding/src/namespace.h"

#include "EXPRESSObject.h"

#include <tuple>
#include <utility>


OIP_NAMESPACE_OPENINFRAPLATFORM_EARLYBINDING_BEGIN


class EXPRESSEntity : public EXPRESSObject {
public:
	const size_t getId() const {
		return m_id;
	}

	void setId(size_t id) {
		m_id = id;
	}

	const std::string getStepParameter() const override {
		return "#" + std::to_string(m_id);
	}

	const std::string getErrorLog() const {
		return classname() + ": (" + getStepParameter() + ")";
	}

	virtual const std::string classname() const = 0;

	virtual const std::string getStepLine() const = 0;

protected:
	size_t m_id;
};

OIP_NAMESPACE_OPENINFRAPLATFORM_EARLYBINDING_END

EMBED_INTO_OIP_NAMESPACE(EXPRESSEntity);

#endif // end define OpenInfraPlatform_EarlyBinding_EXPRESSEntity_5fd9c3bc_1d26_4fef_994f_229551a1c3f8_h
