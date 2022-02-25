#pragma once

#include "Serializable.h"
#include <string>

class Parser
{
private:
	std::string m_sData{};
	std::size_t m_nOffset = 0;

public:
	Parser() noexcept = default;

	Parser(const std::string &str) noexcept
	{
		m_sData = str;
	}

private:
	char get_char(const std::size_t index) noexcept
	{
		return m_sData.at(index + m_nOffset);
	}

public:
	void setContent(const std::string &str) noexcept
	{
		m_sData = str;
		m_nOffset = 0;
	}

	std::string getContent() const noexcept
	{
		return m_sData;
	}

	std::size_t size() const noexcept
	{
		return content_size() - offset();
	}

	std::size_t offset() const noexcept
	{
		return m_nOffset;
	}

	std::size_t content_size() const noexcept
	{
		return m_sData.size();
	}

public:
	template <class T>
	T parse() noexcept
	{
		Serializable<T> s{};

		for (std::size_t i = 0; i < s.size(); i++)
			s.data[i] = get_char(i);
		m_nOffset += s.size();

		return s.object;
	}
};
