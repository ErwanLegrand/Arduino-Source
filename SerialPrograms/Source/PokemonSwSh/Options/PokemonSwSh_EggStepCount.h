/*  Egg Step Count Dropdown
 *
 *  From: https://github.com/PokemonAutomation/Arduino-Source
 *
 */

#ifndef PokemonAutomation_PokemonSwSh_EggStepCount_H
#define PokemonAutomation_PokemonSwSh_EggStepCount_H

#include <stdint.h>
#include <vector>
#include <QComboBox>
#include "CommonFramework/Options/ConfigOption.h"

namespace PokemonAutomation{

extern const std::vector<uint16_t> STEP_COUNTS;

class EggStepCountOption : public ConfigOption{
public:
    EggStepCountOption();
    virtual void load_json(const QJsonValue& json) override;
    virtual QJsonValue to_json() const override;

    operator uint16_t() const{ return STEP_COUNTS[m_current]; }
    uint16_t value() const{ return STEP_COUNTS[m_current]; }

    virtual void restore_defaults() override;

    virtual ConfigOptionUI* make_ui(QWidget& parent) override;


private:
    friend class EggStepCountUI;
    QString m_label;
    const size_t m_default;
    size_t m_current;
};


class EggStepCountUI : public QWidget, public ConfigOptionUI{
public:
    EggStepCountUI(QWidget& parent, EggStepCountOption& value);
    virtual void restore_defaults() override;

private:
    EggStepCountOption& m_value;
    QComboBox* m_box;
};


}
#endif

