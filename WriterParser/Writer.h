 #pragma once

#include <string>
#include "Serializable.h"


class Writer
{
	std::string m_sData{};

public:
	Writer() noexcept = default;

	Writer(const std::string &sData) noexcept
	{
		m_sData = sData;
	}

public:
	std::string getContent() const noexcept
	{
		return m_sData;
	}

	void setContent(const std::string sContent) noexcept
	{
		m_sData = sContent;
	}

public:
	template <class T>
	void writeSerializable(const Serializable<T> &objectData) noexcept
	{
		for (size_t i = 0; i < objectData.size(); i++)
			m_sData.push_back(objectData.data[i]);
	}

	template <class T>
	void write(const T &object) noexcept
	{
		writeSerializable(Serializable<T>(object));
	}
};
