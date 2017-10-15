/*
 * Copyright (C) 2017  Andrew Gunnerson <andrewgunnerson@gmail.com>
 *
 * This file is part of DualBootPatcher
 *
 * DualBootPatcher is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DualBootPatcher is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DualBootPatcher.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "mbcommon/common.h"

#include "mbcommon/error/error_info.h"

namespace mb
{

enum class FileErrorType
{
    ArgumentOutOfRange      = 10,
    CannotConvertEncoding   = 11,

    InvalidState            = 20,
    ObjectMoved             = 21,

    UnsupportedRead         = 30,
    UnsupportedWrite        = 31,
    UnsupportedSeek         = 32,
    UnsupportedTruncate     = 33,

    IntegerOverflow         = 40,
};

class MB_EXPORT FileError : public ErrorInfo<FileError>
{
public:
    static char ID;

    FileError(FileErrorType type);
    FileError(FileErrorType type, std::string details);

    std::string message() const override;

    FileErrorType type() const;
    std::string details() const;

private:
    FileErrorType _type;
    std::string _details;
};

}
