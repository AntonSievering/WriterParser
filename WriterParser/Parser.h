#pragma once

#include <string>
#include "Serializable.h"

class BaseParser
{
protected:
	std::string m_sData{};
	uint64_t    m_nOffset = 0;

public:
	bool hasData() const noexcept
	{
		return m_sData.size() > m_nOffset;
	}
};


class Parser : public BaseParser
{
public:
	Parser() noexcept = default;

	Parser(const std::string &sData) noexcept
	{
		m_sData = sData;
	}

	Parser(std::string &&sData) noexcept
	{
		m_sData = sData;
	}

public:
	template <class T>
	T parse() noexcept
	{
		Serializable<T> buffer{};
		
		for (uint64_t i = 0; i < buffer.size(); i++)
			buffer.data[i] = m_sData.at(i + m_nOffset);
		m_nOffset += buffer.size();

		return buffer.object;
	}
};


class StackParser : public BaseParser
{
public:
	StackParser() noexcept = default;

	StackParser(const std::string &sData) noexcept
	{
		m_sData = sData;
	}

	StackParser(std::string &&sData) noexcept
	{
		m_sData = sData;
	}

public:
	template <class T>
	T parse() noexcept
	{
		Serializable<T> buffer{};
		m_nOffset += buffer.size();
		uint64_t nBeginOffset = m_sData.size() - m_nOffset;

		for (uint64_t i = 0; i < buffer.size(); i++)
			buffer.data[i] = m_sData.at(i + nBeginOffset);

		return buffer.object;
	}
};
