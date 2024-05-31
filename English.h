#pragma once
#include "Language.h"
#include <string>

using namespace std;

class English : public Language
{
public:
    string loginAndRegisterPage() const override;
    string menu() const override;
    string tableTitle() const override;
    English();
    
};

