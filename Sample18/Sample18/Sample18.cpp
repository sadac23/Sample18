// Sample18.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "sample18.h"
#include <iostream>
#include <memory>

int main()
{
	std::cout << "<< サンプルコード開始 >>\n";
	int i;

	/* 引数をひとつだけとるコンストラクタについては，明示的呼び出しと暗黙的呼び出しの2つの呼び出し方がある */

	//Date d(30, 3, 1995);		//Explicitがない場合は有効
	//Date d(Month(3), Day(3), Year(1995));		//struct
	//Date d(Month::Jan(), Day(3), Year(1995));	//class
	//Date d(Month(13), Day(3), Year(1995));		//class

	/* クライアントが何かを覚えておかなければならないようなインタフェースは誤用される可能性が高いもの */
	f();

	std::cout << "<< サンプルコード終了 >>";
	std::cin >> i;

	return 0;
}

void f() {
	//破棄責任が呼び元にある　→　破棄が保障されない
	//Investment* plnv = Investment::CreateInvestment();
	//delete plnv;

	//スマートポインタにインスタンスを渡す　→　スマートポインタに渡される保障はない
	//Investment* p = Investment::CreateInvestment();
	//std::tr1::shared_ptr<Investment> plnv(p);

	//スマートポインタの使用を強制する
	//Investment* p = Investment::CreateInvestment();		//エラー
	//std::tr1::shared_ptr<Investment> plnv(Investment::CreateInvestment());

	//カスタムデリータによる破棄
	std::tr1::shared_ptr<Investment> plnv(Investment::CreateInvestment(), Investment::GetRidOfInvestment);
}

Investment::Investment() {
	std::cout << "[Investment::Investment]リソース取得\n";
}
Investment::~Investment() {
	std::cout << "[Investment::~Investment]リソース解放\n";
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
	std::cout << "[Investment::GetRidOfInvestment]リソース解放\n";
}
