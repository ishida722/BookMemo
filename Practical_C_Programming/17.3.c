// �����N���X�g
struct linked_list {
	char data[30];
	struct linked_list *next_ptr;
};

// �ŏ��̃|�C���^��錾�A���X�g�͋�Ȃ̂�NULL���w��
struct linked_list *first_ptr = NULL;

// �V�����v�f�����X�g�ɒǉ�����
// �܂����ڂ̍\���̂��쐬
struct linked_list new_item_ptr;
new_item_ptr =malloc(sizeof(struct linked_list));

// �V�����v�f�Ƀf�[�^���i�[
strcpy((*new_item_ptr).data, "item name");

// ���X�g�̐擪�ɐV�����v�f��ǉ�
(*new_item_ptr).next_ptr = first_ptr;
first_ptr = new_item_ptr;


// ���X�g���̗v�f�����Ɍ�������

int find(char *name)
{
	// �J�[�\��
	struct linked_list *current_ptr;

	current_ptr = first_ptr;

	// stucmp �͓������Ƃ���0��Ԃ��A�������Ȃ��Ƃ��͂���ȊO��Ԃ�
	// �����Ƀ}�b�`�����A���J�[�\����NULL�łȂ��Ƃ�
	while ((strcmp(current_ptr->data, name) != 0) &&
			(current_ptr != NULL))
		// �J�[�\�������̃m�[�h�Ɉړ�����
		current_ptr = current_ptr->next_ptr;
	// �}�b�`���邩�A�J�[�\����NULL�ɂȂ����Ƃ����[�v���甲����

	// �Ԃ�l�̓J�[�\����NULL�łȂ��Ȃ�ture NULL�Ȃ�false
	return (current_ptr != NULL);
}

// �����������N���X�g
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
