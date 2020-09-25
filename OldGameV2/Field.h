#pragma once

#include<vector>
#include<string>
#include<deque>

#include"Basic_Elemental.h"

class VoidField {
	protected:
		std::vector<std::vector<Elemental>> m_elementals;
		std::string m_name;
		bool m_field_type;
	public:
		VoidField();
		VoidField(int);
		std::string GetName();
		void FieldOptions(std::string,std::deque<int>&);
		VoidField& operator= (const VoidField&);
		void MakeElemental(Elemental&,std::string, std::deque<int>&);
		void EndOfTurn(std::deque<int>&,std::string);
		void ElementalAction(std::deque<int>&,std::string);
		virtual void FieldFeature();
};