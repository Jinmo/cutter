#ifndef TESTFORM_H
#define TESTFORM_H

#include <QWidget>
#include "AbstractCommandPaletteWidget.h"

namespace Ui
{
	class SimpleCommandPaletteWidget;
}

class QTreeView;
class MainWindow;


class SimpleCommandPaletteWidget : public AbstractCommandPaletteWidget
{
		Q_OBJECT

	public:
        explicit SimpleCommandPaletteWidget( MainWindow *main, QWidget* parent = 0 );
		~SimpleCommandPaletteWidget();

		inline qreal minimumPopUpWidth() const { return m_minPopUpWidth; }
		QString placeholderText();

		void setPlaceholderText( QString text );
		inline void setMinimumPopUpWidth( int width ) { m_minPopUpWidth = width; }

        void setupCompleter();
        void refresh(const QStringList &flagList);
private slots:
		void on_lineEdit_textChanged( QString text );
		void onSearchResultsReady( QList<QAction*> results ) override;
		void onShortcutPressed() override;
		void onListViewClicked( const QModelIndex& index );
		// 	void onNextSuggestionRequested() override;
        // 	void onPreviousSuggestionRequested() override;

        void restoreCompleter();
        void on_gotoEntry_returnPressed();
protected:
		virtual void keyReleaseEvent( QKeyEvent* event ) override;
		virtual void focusInEvent( QFocusEvent* event ) override;

	private:
		void showPopup();

		Ui::SimpleCommandPaletteWidget* ui;
		QTreeView* m_listView = nullptr; ///< Popup-list with suggestions
		int m_minPopUpWidth =  300; ///< Minimum width up of popup widget
        QStringList flags;
        MainWindow *main;

};

#endif // TESTFORM_H
