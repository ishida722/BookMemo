// リンクリスト
struct linked_list {
	char data[30];
	struct linked_list *next_ptr;
};

// 最初のポインタを宣言、リストは空なのでNULLを指す
struct linked_list *first_ptr = NULL;

// 新しい要素をリストに追加する
// まず項目の構造体を作成
struct linked_list new_item_ptr;
new_item_ptr =malloc(sizeof(struct linked_list));

// 新しい要素にデータを格納
strcpy((*new_item_ptr).data, "item name");

// リストの先頭に新しい要素を追加
(*new_item_ptr).next_ptr = first_ptr;
first_ptr = new_item_ptr;


// リスト内の要素を順に検索する

int find(char *name)
{
	// カーソル
	struct linked_list *current_ptr;

	current_ptr = first_ptr;

	// stucmp は等しいときに0を返し、等しくないときはそれ以外を返す
	// 検索にマッチせず、かつカーソルがNULLでないとき
	while ((strcmp(current_ptr->data, name) != 0) &&
			(current_ptr != NULL))
		// カーソルを次のノードに移動する
		current_ptr = current_ptr->next_ptr;
	// マッチするか、カーソルがNULLになったときループから抜ける

	// 返り値はカーソルがNULLでないならture NULLならfalse
	return (current_ptr != NULL);
}

// 順序つきリンクリスト
void enter(struct item *first_ptr, const int value)
{
	struct item *before_ptr;
	struct item *after_ptr;
	struct item *new_item_ptr;

	before_ptr = first_ptr;
	after_ptr = before_ptr->next_ptr;

	while (1){
		if (after_ptr == NULL)
			break;
		if (after_ptr->value >= value)
			break;

		after_ptr = after_ptr->next_ptr;
		before_ptr = before_ptr->next_ptr
	}

	new_item_ptr= malloc(sizeof(struct item));
	new_item_ptr->value = value;

	before_ptr->next_ptr = new_item_ptr;
	new_item_ptr->next_ptr = after_ptr;
}
