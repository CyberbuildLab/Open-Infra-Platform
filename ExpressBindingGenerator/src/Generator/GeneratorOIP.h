/*
    This file is part of TUM Open Infra Platform Early Binding EXPRESS
    Generator, a simple early binding generator for EXPRESS.
    Copyright (c) 2016-2017 Technical University of Munich
    Chair of Computational Modeling and Simulation.

    TUM Open Infra Platform Early Binding EXPRESS Generator is free
    software; you can redistribute it and/or modify it under the terms
    of the GNU General Public License Version 3 as published by the Free
    Software Foundation.

    TUM Open Infra Platform Early Binding EXPRESS Generator is
    distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#ifndef OpenInfraPlatform_ExpressBindingGenerator_GeneratorCPP_18047f8d_098b_4199_b0bb_835a22ba9848_h
#define OpenInfraPlatform_ExpressBindingGenerator_GeneratorCPP_18047f8d_098b_4199_b0bb_835a22ba9848_h

#include "Generator/Generator.h"
#include "Meta/Schema.h"
#include "General/namespace.h"
#include <iostream>

OIP_NAMESPACE_OPENINFRAPLATFORM_EXPRESSBINDINGGENERATOR_BEGIN

class GeneratorOIP : public Generator {
public:
    GeneratorOIP(const std::string& outputDirectory);

    virtual ~GeneratorOIP();

    void generate(std::ostream &out, Schema &schema);

	void generateREFACTORED(std::ostream &out, Schema &schema);

private:
    void createEntitiesMapHeaderFile(Schema &schema);

    void createTypesHeaderFile(Schema &schema);

	void createTypesHeaderFileREFACTORED(Schema &schema);
	
	void createEntitiesHeaderFile(Schema &schema);

	void createEntitiesHeaderFileREFACTORED(Schema &schema);

	void generateEntitySourceFile(Schema &schema, const Entity &entity);

	void generateEntitySourceFileREFACTORED(Schema &schema, const Entity &entity);

    void generateTypeHeaderFile(Schema &schema, Type &type);

	void generateTypeHeaderFileREFACTORED(Schema &schema, Type &type);

    void generateTypeSourceFile(Schema &schema, Type &type);
    
	void generateTypeSourceFileREFACTORED(Schema &schema, Type &type);

    void generateTypeSourceFileGetStepParameter(const Type &type, std::ofstream &out, Schema &schema);

	void generateReaderFiles(const Schema &schema);

	void generateWriterFile(const Schema &schema);

	void generateEMTFiles(const Schema &schema);

    std::string convertSimpleTypeToCPPType(Schema &schema, std::string simpleType) const;

    void includeFile(const std::string &filename, std::ofstream &file);

    void generateCMakeListsFile(const Schema &schema);

	void generateCMakeListsFileREFACTORED(const Schema &schema);


    void createEntityBrokerCPPFile(Schema &schema);

    void generateEntityHeaderFile(Schema &schema, Entity &entity);

	void generateEntityHeaderFileREFACTORED(Schema &schema, Entity &entity);

    void generateEntityEnumsHeaderFile(Schema &schema);

	void generateSchemaHeader(Schema& schema);

	void generateNamespaceHeader(Schema &schema);

private:
    std::string outputDirectory_;
    std::string rootDirectory_;
    std::string sourceDirectory_;
    std::string guidPath_;
    std::string entityPath_;
	std::string typePath_;
    std::string readerPath_;
    std::string modelPath_;
    std::string writerPath_;
    std::string xmlPath_;
};

OIP_NAMESPACE_OPENINFRAPLATFORM_EXPRESSBINDINGGENERATOR_END

EMBED_INTO_OIP_NAMESPACE(GeneratorOIP)

#endif // end define OpenInfraPlatform_ExpressBindingGenerator_GeneratorCPP_18047f8d_098b_4199_b0bb_835a22ba9848_h
