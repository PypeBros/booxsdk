#include "onyx/ui/russian_keyboard_data.h"

namespace ui
{

static const QChar RUSSIAN_LEFT[] = {
        QChar(0x0439), QChar(0x0446), QChar(0x0443),
        QChar(0x044A), QChar(0x0444), QChar(0x044B),
        QChar(0x044E), QChar(0x044F), QChar(0x0447), };

static const QChar RUSSIAN_MIDDLE[] = {
        QChar(0x043A), QChar(0x0435), QChar(0x043D),
        QChar(0x0432), QChar(0x0430), QChar(0x043F),
        QChar(0x0441), QChar(0x043C), QChar(0x0438), };

static const QChar RUSSIAN_RIGHT[] = {
        QChar(0x0433), QChar(0x0448), QChar(0x0449),
        QChar(0x0440), QChar(0x043E), QChar(0x043B),
        QChar(0x0442), QChar(0x044C), QChar(0x0431), };

RussianKeyboardData::RussianKeyboardData()
    : KeyboardData()
{
    initTopKeyCode();
    initLeftKeyCode();
    initMiddleKeyCode();
    initRightKeyCode();
    initBottomKeyCode();

    initTopKeyShiftCode();
    initLeftKeyShiftCode();
    initMiddleKeyShiftCode();
    initRightKeyShiftCode();
    initBottomKeyShiftCode();

    initLeftKeySymbolCode();
    initMiddleKeySymbolCode();
    initRightKeySymbolCode();
}

RussianKeyboardData::~RussianKeyboardData()
{
}

// for initialization
void RussianKeyboardData::initTopKeyCode()
{
    const QChar chs[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    for (int i = 0; i < 10; i++)
    {
        OData *dd = createData(QString(chs[i]));
        top_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initLeftKeyCode()
{
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(RUSSIAN_LEFT[i]));
        left_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initMiddleKeyCode()
{
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(RUSSIAN_MIDDLE[i]));
        middle_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initRightKeyCode()
{
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(RUSSIAN_RIGHT[i]));
        right_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initBottomKeyCode()
{
    const QChar chs[] = {'.', ',', QChar(0x0437), QChar(0x0445),
            QChar(0x0434), ' '};
    for (int i=0; i<6; i++)
    {
        OData *dd = createData(QString(chs[i]));
        bottom_codes_.push_back(dd);
    }

    OData * dd = createBackspaceData();
    bottom_codes_.push_back(dd);

    const QChar chs_next[] = {QChar(0x0436), QChar(0x044D)};
    for (int i=0; i<2; i++)
    {
        OData *dd = createData(QString(chs_next[i]));
        bottom_codes_.push_back(dd);
    }

    dd = createEnterData();
    bottom_codes_.push_back(dd);
}

// for shift key
void RussianKeyboardData::initTopKeyShiftCode()
{
    const QChar chs[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
    for (int i = 0; i < 10; i++)
    {
        OData *dd = createData(QString(chs[i]));
        top_shift_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initLeftKeyShiftCode()
{
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(RUSSIAN_LEFT[i].toUpper()));
        left_shift_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initMiddleKeyShiftCode()
{
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(RUSSIAN_MIDDLE[i].toUpper()));
        middle_shift_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initRightKeyShiftCode()
{
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(RUSSIAN_RIGHT[i].toUpper()));
        right_shift_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initBottomKeyShiftCode()
{
    const QChar chs[] = {';', '\'', QChar(0x0437).toUpper(), QChar(0x0445).toUpper(),
            QChar(0x0434).toUpper(), ' '};
    for (int i=0; i<6; i++)
    {
        OData *dd = createData(QString(chs[i]));
        bottom_shift_codes_.push_back(dd);
    }

    OData * dd = createBackspaceData();
    bottom_shift_codes_.push_back(dd);

    const QChar chs_next[] = {QChar(0x0436).toUpper(), QChar(0x044D).toUpper()};
    for (int i=0; i<2; i++)
    {
        OData *dd = createData(QString(chs_next[i]));
        bottom_shift_codes_.push_back(dd);
    }

    dd = createEnterData();
    bottom_shift_codes_.push_back(dd);
}

// for symbol key
void RussianKeyboardData::initLeftKeySymbolCode()
{
    const QChar chs[] = {'[', ']', '\\',
                         QChar(0x00B5), '/', '`',
                         QChar(0x00AD), QChar(0x00AF), QChar(0x00B7), };
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(chs[i]));
        left_symbol_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initMiddleKeySymbolCode()
{
    const QChar chs[] = {'+', '-', '?',
                         ':', '"', '=',
                         '_', '{', '}', };
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(chs[i]));
        middle_symbol_codes_.push_back(dd);
    }
}

void RussianKeyboardData::initRightKeySymbolCode()
{
    const QChar chs[] = {'~', '<', '>',
                         '|', QChar(0x00A3), QChar(0x00A5),
                         QChar(0x00A7), QChar(0x00A9), QChar(0x00B1), };
    for (int i = 0; i < 9; i++)
    {
        OData *dd = createData(QString(chs[i]));
        right_symbol_codes_.push_back(dd);
    }
}

}
