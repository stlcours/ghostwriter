/***********************************************************************
 *
 * Copyright (C) 2014, 2015 wereturtle
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QFont>

#include "MarkdownEditorTypes.h"
#include "MarkdownStyles.h"

/**
 * Loads and stores application settings via QSettings, particularly for
 * those settings that need special range checking.  Be sure to call
 * getInstance on application start up to set up settings file paths before
 * using QSettings directly for other settings not managed by this class.
 */
class AppSettings
{
    public:
        static const int MIN_TAB_WIDTH = 1;
        static const int MAX_TAB_WIDTH = 8;
        static const int DEFAULT_TAB_WIDTH = 4;

        static AppSettings* getInstance();
        ~AppSettings();

        void store();

        QString getThemeDirectoryPath() const;
        QString getDictionaryPath() const;

        bool getAutoSaveEnabled() const;
        void setAutoSaveEnabled(bool enabled);

        bool getBackupFileEnabled() const;
        void setBackupFileEnabled(bool enabled);

        QFont getFont() const;
        void setFont(const QFont& font);

        int getTabWidth() const;
        void setTabWidth(int width);

        bool getInsertSpacesForTabsEnabled() const;
        void setInsertSpacesForTabsEnabled(bool enabled);

        bool getUseUnderlineForEmphasis() const;
        void setUseUnderlineForEmphasis(bool enabled);

        bool getLargeHeadingSizesEnabled() const;
        void setLargeHeadingSizesEnabled(bool enabled);

        FocusMode getFocusMode() const;
        void setFocusMode(FocusMode focusMode);

        bool getFileHistoryEnabled() const;
        void setFileHistoryEnabled(bool enabled);

        QString getThemeName() const;
        void setThemeName(const QString& name);

        QString getLocale() const;
        void setLocale(const QString& locale);

        bool getLiveSpellCheckEnabled() const;
        void setLiveSpellCheckEnabled(bool enabled);

        EditorWidth getEditorWidth() const;
        void setEditorWidth(EditorWidth editorWidth);

        BlockquoteStyle getBlockquoteStyle() const;
        void setBlockquoteStyle(BlockquoteStyle style);

        bool getAlternateHudRowColorsEnabled() const;
        void setAlternateHudRowColorsEnabled(bool enabled);

        bool getDesktopCompositingEnabled() const;
        void setDesktopCompositingEnabled(bool enabled);

        int getHudOpacity() const;
        void setHudOpacity(int value);

    private:
        AppSettings();

        static AppSettings* instance;
        QString themeDirectoryPath;
        QString dictionaryPath;

        QFont defaultFont;
        bool autoSaveEnabled;
        bool backupFileEnabled;
        QFont font;
        int tabWidth;
        bool insertSpacesForTabsEnabled;
        bool useUnderlineForEmphasis;
        bool largeHeadingSizesEnabled;
        FocusMode focusMode;
        bool fileHistoryEnabled;
        QString themeName;
        QString locale;
        bool liveSpellCheckEnabled;
        EditorWidth editorWidth;
        BlockquoteStyle blockquoteStyle;
        bool alternteHudRowColorsEnabled;
        bool desktopCompositingEnabled;
        int hudOpacity;
};

#endif // APPSETTINGS_H
