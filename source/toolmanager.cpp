#include "toolmanager.h"

/**
 * @brief ToolManager::ToolManager
 */
ToolManager::ToolManager()
{
    this->_currentColor = Qt::black;
    this->_currentWidth = 3;
    this->_currentToolType = ToolType::Pen;
    this->_currentTool = std::shared_ptr<ITool>(new Pen());

    _toolList = {
        {
            ToolType::Pen, [](){
                return std::shared_ptr<ITool>(new Pen());
            }
        },

        {
            ToolType::Line, [](){
                return std::shared_ptr<ITool>(new Line());
            }
        },

        {
            ToolType::Rectangle, [](){
                return std::shared_ptr<ITool>(new Rectangle());
            }
        },

        {
            ToolType::Circle, [](){
                return std::shared_ptr<ITool>(new Circle());
            }
        },

        {
            ToolType::Eraser, [](){
                return std::shared_ptr<ITool>(new Eraser());
            }
        },

        {
            ToolType::Brush, [](){
                return std::shared_ptr<ITool>(new Brush());
            }
        },

        {
            ToolType::Bucket, [](){
                return std::shared_ptr<ITool>(new Bucket());
            }
        }
    };
}

ToolType ToolManager::currentToolType() const
{
    return _currentToolType;
}

void ToolManager::setCurrentToolType(const ToolType &currentToolType)
{
    _currentToolType = currentToolType;
}

/**
 * @brief ToolManager::getInstance
 * @return
 */
ToolManager& ToolManager::getInstance()
{
    static ToolManager instance;
    return instance;
}

/**
 * @brief ToolManager::setCurrentWidth
 * @param width
 */
void ToolManager::setCurrentWidth(int width)
{
    _currentWidth = width;
}

/**
 * @brief ToolManager::getCurrentWidth
 * @return
 */
int ToolManager::currentWidth() const
{
    return _currentWidth;
}

/**
 * @brief ToolManager::currentColor
 * @param color
 */
void ToolManager::setCurrentColor(const QColor &color)
{
    _currentColor = color;
}

/**
 * @brief ToolManager::getCurrentColor
 * @return
 */
QColor ToolManager::currentColor() const
{
    return _currentColor;
}

/**
 * @brief ToolManager::getToolByType
 * @param type
 * @return
 */
std::shared_ptr<ITool> ToolManager::getToolByType(ToolType type)
{
    /* Check if tool existed in Map */
    auto iter = this->_toolList.find(type);
    if(iter == this->_toolList.end())
    {
        throw std::runtime_error("No shape with such ID program is available to draw!");
    }

    /* Create new Tool object */
    std::shared_ptr<ITool> newTool((*iter)());
    newTool->setColor(this->_currentColor);
    newTool->setWidth(this->_currentWidth);

    return newTool;
}

/**
 * @brief ToolManager::getCurrentTool
 * @return
 */
std::shared_ptr<ITool> ToolManager::currentTool() const
{
    return _currentTool;
}

/**
 * @brief ToolManager::startDraw
 * @param point
 */
void ToolManager::startDraw(const QPoint &point)
{
    /* Set up new tool */
    this->_currentTool = this->getToolByType(this->_currentToolType);
    /* Make call to draw action in current tool */
    this->_currentTool->startDraw(point);
}

/**
 * @brief ToolManager::endDraw
 * @param point
 */
void ToolManager::endDraw(const QPoint &point)
{
    this->_currentTool->endDraw(point);
}

/**
 * @brief ToolManager::setNewToolType
 * @param type
 */
void ToolManager::setCurrentTool(ToolType type)
{
    this->_currentToolType = type;
    this->_currentTool = this->getToolByType(type);
}
