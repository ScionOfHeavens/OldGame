#include "Volcano.h"

Volcano::Volcano()
{
	m_name = "Volcano";
	m_field_type = 1;
}

void Volcano::FieldFeature()
{
	for (int i = 0; i < m_elementals.size(); i++)
		for (int j = 0; j < m_elementals.size(); j++)
			m_elementals[i][j].TakeDamage(5,1);
}