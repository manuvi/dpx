// -*- mode: C++; tab-width: 4 -*-
// vi: ts=4

/*
 * Copyright (c) 2009, Patrick A. Palmer.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Patrick A. Palmer nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef _DPX_COLORCONVERTER_H
#define _DPX_COLORCONVERTER_H 1


#include "DPX.h"


namespace dpx
{
	// convert between all of the various pixel formats and RGB in a controllable way
	
	/*!
	* \brief Query the size of the buffer necessary to hold the decoded RGB data
	* \param header DPX header
	* \param element image element (0-7)
	* \param block image area (used only for calculating the amount of pixels,
	* not an offset into the buffer)
	* \return zero: conversion impossible or unsupported absolute value: size
	* of the buffer in bytes; sign: positive - memory needs to be allocated,
	* negative - allocation is optional, decoded data can replace the input
	*/
	int QueryBufferSize(const Header &header, const int element, const Block &block);

	/*!
	* \brief Query the size of the buffer necessary to hold the decoded RGB data
	* \param header DPX header
	* \param element image element (0-7)
	* \return zero: conversion impossible or unsupported; absolute value: size
	* of the buffer in bytes; sign: positive - memory needs to be allocated,
	* negative - allocation is optional, decoded data can replace the input
	*/
	int QueryBufferSize(const Header &header, const int element);

	/*!
	* \brief Convert data from the input buffer into RGB in the output buffer
	* \param header DPX header
	* \param element image element (0-7)
	* \param input input buffer data
	* \param output output buffer data
	* \param block image area (used only for calculating the amount of pixels,
	* not an offset into the buffer)
	* \return success true/false
	*/
	bool ConvertToRGB(const Header &header, const int element, const void *input, const void *output, const Block &block);

	/*!
	* \brief Convert data from the input buffer into RGB in the output buffer
	* \param header DPX header
	* \param element image element (0-7)
	* \param input input buffer data
	* \param output output buffer data
	* \return success true/false
	*/
	bool ConvertToRGB(const Header &header, const int element, const void *input, const void *output);

}


#endif


