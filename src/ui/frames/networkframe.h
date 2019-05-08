#ifndef NETWORKFRAME_H
#define NETWORKFRAME_H

#include <QWidget>
#include <memory>

class QRegularExpressionValidator;

namespace installer {
class LineEdit;
class NavButton;
class SystemInfoTip;
class NetworkFrame : public QWidget {
    Q_OBJECT
public:
    explicit NetworkFrame(QWidget* parent = nullptr);

signals:
    void requestNext();

private:
    void saveConf();

private:
    LineEdit*                                    m_ipv4Edit;
    LineEdit*                                    m_maskEdit;
    LineEdit*                                    m_primaryDNSEdit;
    LineEdit*                                    m_secondDNSEdit;
    NavButton*                                   m_skipButton;
    NavButton*                                   m_saveButton;
    std::unique_ptr<QRegularExpressionValidator> m_validityCheck;
};
}  // namespace installer

#endif  // NETWORKFRAME_H
