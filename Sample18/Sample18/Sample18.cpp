// Sample18.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "sample18.h"
#include <iostream>
#include <memory>

int main()
{
	std::cout << "<< �T���v���R�[�h�J�n >>\n";
	int i;

	/* �������ЂƂ����Ƃ�R���X�g���N�^�ɂ��ẮC�����I�Ăяo���ƈÖٓI�Ăяo����2�̌Ăяo���������� */

	//Date d(30, 3, 1995);		//Explicit���Ȃ��ꍇ�͗L��
	//Date d(Month(3), Day(3), Year(1995));		//struct
	//Date d(Month::Jan(), Day(3), Year(1995));	//class
	//Date d(Month(13), Day(3), Year(1995));		//class

	/* �N���C�A���g���������o���Ă����Ȃ���΂Ȃ�Ȃ��悤�ȃC���^�t�F�[�X�͌�p�����\������������ */
	f();

	std::cout << "<< �T���v���R�[�h�I�� >>";
	std::cin >> i;

	return 0;
}

void f() {
	//�j���ӔC���Ăь��ɂ���@���@�j�����ۏႳ��Ȃ�
	//Investment* plnv = Investment::CreateInvestment();
	//delete plnv;

	//�X�}�[�g�|�C���^�ɃC���X�^���X��n���@���@�X�}�[�g�|�C���^�ɓn�����ۏ�͂Ȃ�
	//Investment* p = Investment::CreateInvestment();
	//std::tr1::shared_ptr<Investment> plnv(p);

	//�X�}�[�g�|�C���^�̎g�p����������
	//Investment* p = Investment::CreateInvestment();		//�G���[
	//std::tr1::shared_ptr<Investment> plnv(Investment::CreateInvestment());

	//�J�X�^���f���[�^�ɂ��j��
	std::tr1::shared_ptr<Investment> plnv(Investment::CreateInvestment(), Investment::GetRidOfInvestment);
}

Investment::Investment() {
	std::cout << "[Investment::Investment]���\�[�X�擾\n";
}
Investment::~Investment() {
	std::cout << "[Investment::~Investment]���\�[�X���\n";
}
Investment* Investment::CreateInvestment(){
return new Investment();
}
/*
std::tr1::shared_ptr<Investment> Investment::CreateInvestment() {
	std::tr1::shared_ptr<Investment> plnv(new Investment());
	return plnv;
}
*/
void Investment::GetRidOfInvestment(Investment* p) {
	std::cout << "[Investment::GetRidOfInvestment]���\�[�X���\n";
}
