/*
 * Material.h
 *
 *  Created on: Aug 19, 2013
 *      Author: Jenna
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "Algebra.h"

class Material {
public:
	virtual ~Material();
	virtual void apply_gl() const = 0;

protected:
	Material()
  	{}
};

class PhongMaterial : public Material {
public:
	PhongMaterial( const Colour& kd, const Colour& ks, double shininess );
	virtual ~PhongMaterial();

	virtual void apply_gl() const;

private:
	Colour m_kd;
	Colour m_ks;

	double m_shininess;
};

#endif /* MATERIAL_H_ */
