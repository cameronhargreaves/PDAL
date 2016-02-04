/******************************************************************************
* Copyright (c) 2014, Hobu Inc., hobu.inc@gmail.com
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following
* conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in
*       the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Hobu, Inc. or Flaxen Geo Consulting nor the
*       names of its contributors may be used to endorse or promote
*       products derived from this software without specific prior
*       written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
****************************************************************************/

#pragma once

#include <algorithm>
#include <map>
#include <vector>

namespace pdal
{

namespace Utils
{

template<typename CONTAINER, typename VALUE>
bool contains(const CONTAINER& cont, const VALUE& val)
{
    return std::find(cont.begin(), cont.end(), val) != cont.end();
}


template<typename KEY, typename VALUE>
bool contains(const std::map<KEY, VALUE>& c, const KEY& v)
{
    return c.find(v) != c.end();
}


template<typename CONTAINER, typename VALUE>
void remove(CONTAINER& v, const VALUE& val)
{
    v.erase(std::remove(v.begin(), v.end(), val), v.end());
}


template<typename CONTAINER, typename PREDICATE>
void remove_if(CONTAINER& v, PREDICATE p)
{
    v.erase(std::remove_if(v.begin(), v.end(), p), v.end());
}
/**
template<typename TYPE, typename VALUE>
void remove(std::vector<TYPE>& v, const VALUE& val)
{
    v.erase(std::remove(v.begin(), v.end(), val), v.end());
}


template<typename TYPE, typename PREDICATE>
void remove_if(std::vector<TYPE>& v, PREDICATE p)
{
    v.erase(std::remove_if(v.begin(), v.end(), p), v.end());
}
**/

} // namespace Utils
} // namespace pdal

