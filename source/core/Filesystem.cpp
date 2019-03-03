/*
 * =====================================================================================
 *
 *       Filename:  Filesystem.cpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 17:35:37
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <sys/types.h>
#include <sys/stat.h>

#include "Filesystem.hpp"

bool Filesystem::fileExists(const std::string &filename) {
	struct stat info;

	return !stat(filename.c_str(), &info);
}

