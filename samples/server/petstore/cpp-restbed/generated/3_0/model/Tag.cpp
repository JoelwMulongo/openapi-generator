/**
 * OpenAPI Petstore
 * This spec is mainly for testing Petstore server and contains fake endpoints, models. Please do not use this for any other purpose. Special characters: \" \\
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 6.3.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "Tag.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "helpers.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

namespace org {
namespace openapitools {
namespace server {
namespace model {

Tag::Tag(boost::property_tree::ptree const& pt)
{
        fromPropertyTree(pt);
}


std::string Tag::toJsonString(bool prettyJson /* = false */) const
{
	std::stringstream ss;
	write_json(ss, this->toPropertyTree(), prettyJson);
    // workaround inspired by: https://stackoverflow.com/a/56395440
    std::regex reg("\\\"([0-9]+\\.{0,1}[0-9]*)\\\"");
    std::string result = std::regex_replace(ss.str(), reg, "$1");
    return result;
}

void Tag::fromJsonString(std::string const& jsonString)
{
	std::stringstream ss(jsonString);
	ptree pt;
	read_json(ss,pt);
	this->fromPropertyTree(pt);
}

ptree Tag::toPropertyTree() const
{
	ptree pt;
	ptree tmp_node;
	pt.put("id", m_Id);
	pt.put("name", m_Name);
	return pt;
}

void Tag::fromPropertyTree(ptree const &pt)
{
	ptree tmp_node;
	m_Id = pt.get("id", 0L);
	m_Name = pt.get("name", "");
}

int64_t Tag::getId() const
{
    return m_Id;
}

void Tag::setId(int64_t value)
{
    m_Id = value;
}


std::string Tag::getName() const
{
    return m_Name;
}

void Tag::setName(std::string value)
{
    m_Name = value;
}



std::vector<Tag> createTagVectorFromJsonString(const std::string& json)
{
    std::stringstream sstream(json);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream,pt);

    auto vec = std::vector<Tag>();
    for (const auto& child: pt) {
        vec.emplace_back(Tag(child.second));
    }

    return vec;
}

}
}
}
}

