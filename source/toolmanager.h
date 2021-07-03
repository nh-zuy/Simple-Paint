#ifndef TOOLMANAGER_H
#define TOOLMANAGER_H

#include <QMap>
#include <QColor>
#include <QString>
#include <QMessageBox>
#include <exception>
#include <functional>
#include <algorithm>
#include <memory>

#include "shapes/line.h"
#include "tools/pen.h"
#include "tools/brush.h"
#include "tools/bucket.h"
#include "tools/eraser.h"
#include "shapes/rectangle.h"
#include "shapes/circle.h"
#include "tooltype.h"

class ITool;
class Shape;

/**
 * @brief The ToolManager class
 *
 * Manage those used tool in App
 * Implement Singleton (refer to StackOverflow)
 */
class ToolManager
{
private:
    /* Singleton */
    /* Private constructor for Singleton */
    ToolManager();

    /* Current tool */
    ToolType _currentToolType;
    std::shared_ptr<ITool> _currentTool;
    /* Current width tool */
    int _currentWidth;
    /* Current color tool */
    QColor _currentColor;
    /* Map contains all the ITool object */
    QMap<ToolType, std::function<std::shared_ptr<ITool>()>> _toolList;
public:
    /* Similar above, this can help disalowing copying */
    ToolManager(const ToolManager&) = delete;
    const ToolManager& operator=(const ToolManager&) = delete;
    /* Get static instance */
    static ToolManager& getInstance();

    /* Set this tool type in currently working */
    void setCurrentTool(ToolType type);
    /* Get current tool */
    std::shared_ptr<ITool> currentTool() const;

    /* Get existed tool in Map by ToolType */
    std::shared_ptr<ITool> getToolByType(ToolType type);

    /* Getter/Setter width tool */
    void setCurrentWidth(int width);
    int currentWidth() const;

    /* Getter/setter color tool */
    void setCurrentColor(const QColor &color);
    QColor currentColor() const;

    /**
     * Working with draw user action
     * Initialize start point when the very fisrt user click
     * And very last user click
     */
    void startDraw(const QPoint& point);
    void endDraw(const QPoint& point);

    ToolType currentToolType() const;
    void setCurrentToolType(const ToolType &currentToolType);
};

#endif
