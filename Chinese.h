#pragma once
#include "Language.h"


using namespace std;

class Chinese : public Language
{
public:
    string loginAndRegisterPage() const override;
    string menu() const override;
    string tableTitle() const override;
    Chinese();
};

