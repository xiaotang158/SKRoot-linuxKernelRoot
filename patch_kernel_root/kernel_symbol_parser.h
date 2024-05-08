﻿#pragma once
#include "kernel_version_parser.h"
#include "kallsyms_lookup_name.h"
#include "kallsyms_lookup_name_4_6_0.h"
#include <iostream>
#include <vector>
class KernelSymbolParser
{
public:
	KernelSymbolParser(const std::vector<char>& file_buf);
	~KernelSymbolParser();

public:
	bool init_kallsyms_lookup_name();
	uint64_t kallsyms_lookup_name(const char* name, bool include_str_mode = false);
private:
	const std::vector<char>& m_file_buf;
	KernelVersionParser m_kernel_ver_parser;
	KallsymsLookupName m_kallsyms_lookup_name;
	KallsymsLookupName_4_6_0 m_kallsyms_lookup_name_4_6_0;
};