/******************************************************************************
* Copyright (c) 2011, Michael P. Gerlek (mpg@flaxen.com)
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

#include <boost/test/unit_test.hpp>
#include <boost/cstdint.hpp>

#include <libpc/drivers/faux/Reader.hpp>
#include <libpc/drivers/faux/Writer.hpp>

using namespace libpc;

BOOST_AUTO_TEST_SUITE(FauxWriterTest)

BOOST_AUTO_TEST_CASE(test_1)
{
    Bounds<double> bounds(1.0, 2.0, 3.0, 101.0, 102.0, 103.0);
    libpc::drivers::faux::Reader reader(bounds, 1000, libpc::drivers::faux::Reader::Constant);

    libpc::drivers::faux::Writer writer(reader);
    BOOST_CHECK(writer.getName() == "Faux Writer");

    boost::uint64_t numWritten = writer.write(750);

    BOOST_CHECK(numWritten == 750);

    BOOST_CHECK(writer.getMinX() == 1.0);
    BOOST_CHECK(writer.getMinY() == 2.0);
    BOOST_CHECK(writer.getMinZ() == 3.0);
    BOOST_CHECK(writer.getMaxX() == 1.0);
    BOOST_CHECK(writer.getMaxY() == 2.0);
    BOOST_CHECK(writer.getMaxZ() == 3.0);
    BOOST_CHECK(writer.getAvgX() == 1.0);
    BOOST_CHECK(writer.getAvgY() == 2.0);
    BOOST_CHECK(writer.getAvgZ() == 3.0);

    return;
}

BOOST_AUTO_TEST_CASE(test_2)
{
    Bounds<double> bounds(1.0, 2.0, 3.0, 101.0, 102.0, 103.0);
    libpc::drivers::faux::Reader reader(bounds, 1000, libpc::drivers::faux::Reader::Random);

    libpc::drivers::faux::Writer writer(reader);

    boost::uint64_t numWritten = writer.write(750);

    BOOST_CHECK(numWritten == 750);

    // test all the values to +/- 10%
    BOOST_CHECK(Utils::compare_approx<float>(writer.getMinX(), 1.0, 10.0));
    BOOST_CHECK(Utils::compare_approx<float>(writer.getMinY(), 2.0, 10.0));
    BOOST_CHECK(Utils::compare_approx<float>(writer.getMinZ(), 3.0, 10.0));
    BOOST_CHECK(Utils::compare_approx<float>(writer.getMaxX(), 101.0, 10.0));
    BOOST_CHECK(Utils::compare_approx<float>(writer.getMaxY(), 102.0, 10.0));
    BOOST_CHECK(Utils::compare_approx<float>(writer.getMaxZ(), 103.0, 10.0));
    BOOST_CHECK(Utils::compare_approx<float>(writer.getAvgX(), 51.0, 10.0));
    BOOST_CHECK(Utils::compare_approx<float>(writer.getAvgY(), 52.0, 10.0));
    BOOST_CHECK(Utils::compare_approx<float>(writer.getAvgZ(), 53.0, 10.0));

    return;
}

BOOST_AUTO_TEST_SUITE_END()
