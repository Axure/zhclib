/**
 * @file Memory.h
 * @author Zhang Hai
 */

/*
 * Copyright (C) 2014 Zhang Hai
 *
 * This file is part of zhclib.
 *
 * zhclib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * zhclib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with zhclib.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MEMORY_H_
#define _MEMORY_H_


#include "primitives.h"


void *Memory_allocate(size_t size);

#define Memory_allocateType(type) Memory_allocate(sizeof(type))

void *Memory_reallocate(void *address, size_t size);

void Memory_free(void *address);


#endif /* _MEMORY_H_ */
