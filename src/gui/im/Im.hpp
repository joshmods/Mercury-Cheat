/*
 * Im.hpp
 *
 *  Created on: May 21, 2017
 *      Author: nullifiedcat
 */

#ifndef IM_HPP_
#define IM_HPP_

class CatVar;

namespace menu { namespace im {

void CatVar_Integer(CatVar& var);
void CatVar_Float(CatVar& var);
void CatVar_Enum(CatVar& var);
void CatVar_String(CatVar& var);
void CatVar_Key(CatVar& var);
void CatVar_Switch(CatVar& var);

void Render();

}}

#endif /* IM_HPP_ */
