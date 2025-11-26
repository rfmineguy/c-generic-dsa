#include "tests.h"
#include "../../dsaimpls/ht_str_int.h"

typedef struct {
  const char* key;
  int value;
  bool found;
} test_pair;

#define TEST_PAIR_COUNT 200
test_pair test_pairs[200] = {
    {"k001", 483}, {"k002", 129}, {"k003", 774}, {"k004", 22},
    {"k005", 901}, {"k006", 310}, {"k007", 557}, {"k008", 64},
    {"k009", 742}, {"k010", 508}, {"k011", 119}, {"k012", 833},
    {"k013", 271}, {"k014", 690}, {"k015", 347}, {"k016", 956},
    {"k017", 408}, {"k018", 75}, {"k019", 622}, {"k020", 517},

    {"k021", 302}, {"k022", 886}, {"k023", 144}, {"k024", 967},
    {"k025", 253}, {"k026", 631}, {"k027", 782}, {"k028", 90},
    {"k029", 424}, {"k030", 318}, {"k031", 745}, {"k032", 56},
    {"k033", 657}, {"k034", 211}, {"k035", 890}, {"k036", 373},
    {"k037", 932}, {"k038", 417}, {"k039", 128}, {"k040", 760},

    {"k041", 54}, {"k042", 509}, {"k043", 601}, {"k044", 272},
    {"k045", 948}, {"k046", 365}, {"k047", 812}, {"k048", 421},
    {"k049", 169}, {"k050", 708}, {"k051", 836}, {"k052", 38},
    {"k053", 934}, {"k054", 255}, {"k055", 721}, {"k056", 474},
    {"k057", 60}, {"k058", 846}, {"k059", 393}, {"k060", 519},

    {"k061", 777}, {"k062", 205}, {"k063", 631}, {"k064", 958},
    {"k065", 347}, {"k066", 702}, {"k067", 446}, {"k068", 183},
    {"k069", 970}, {"k070", 524}, {"k071", 689}, {"k072", 412},
    {"k073", 837}, {"k074", 295}, {"k075", 161}, {"k076", 953},
    {"k077", 467}, {"k078", 704}, {"k079", 310}, {"k080", 584},

    {"k081", 14}, {"k082", 726}, {"k083", 673}, {"k084", 91},
    {"k085", 842}, {"k086", 557}, {"k087", 219}, {"k088", 610},
    {"k089", 755}, {"k090", 389}, {"k091", 941}, {"k092", 240},
    {"k093", 828}, {"k094", 109}, {"k095", 670}, {"k096", 385},
    {"k097", 532}, {"k098", 965}, {"k099", 78}, {"k100", 714},

    {"k101", 258}, {"k102", 863}, {"k103", 497}, {"k104", 32},
    {"k105", 774}, {"k106", 186}, {"k107", 945}, {"k108", 400},
    {"k109", 632}, {"k110", 258}, {"k111", 944}, {"k112", 505},
    {"k113", 342}, {"k114", 881}, {"k115", 115}, {"k116", 760},
    {"k117", 621}, {"k118", 433}, {"k119", 206}, {"k120", 540},

    {"k121", 982}, {"k122", 379}, {"k123", 621}, {"k124", 441},
    {"k125", 701}, {"k126", 233}, {"k127", 892}, {"k128", 510},
    {"k129", 376}, {"k130", 664}, {"k131", 90}, {"k132", 817},
    {"k133", 241}, {"k134", 928}, {"k135", 364}, {"k136", 582},
    {"k137", 744}, {"k138", 155}, {"k139", 903}, {"k140", 462},

    {"k141", 521}, {"k142", 267}, {"k143", 800}, {"k144", 319},
    {"k145", 945}, {"k146", 72}, {"k147", 686}, {"k148", 500},
    {"k149", 236}, {"k150", 829}, {"k151", 931}, {"k152", 65},
    {"k153", 472}, {"k154", 710}, {"k155", 888}, {"k156", 139},
    {"k157", 980}, {"k158", 386}, {"k159", 277}, {"k160", 734},

    {"k161", 418}, {"k162", 876}, {"k163", 604}, {"k164", 312},
    {"k165", 759}, {"k166", 53}, {"k167", 927}, {"k168", 284},
    {"k169", 672}, {"k170", 483}, {"k171", 113}, {"k172", 519},
    {"k173", 768}, {"k174", 654}, {"k175", 307}, {"k176", 890},
    {"k177", 224}, {"k178", 995}, {"k179", 458}, {"k180", 742},

    {"k181", 183}, {"k182", 932}, {"k183", 601}, {"k184", 421},
    {"k185", 845}, {"k186", 294}, {"k187", 763}, {"k188", 139},
    {"k189", 910}, {"k190", 487}, {"k191", 525}, {"k192", 661},
    {"k193", 73}, {"k194", 814}, {"k195", 239}, {"k196", 957},
    {"k197", 328}, {"k198", 702}, {"k199", 470}, {"k200", 999}
};

MunitResult ht_test_new(const MunitParameter params[], void* user_data_or_fixture) {
  ht_str_int h = ht_str_int_new(10);
  munit_assert_int(h.buckets_count, ==, 10);
  for (int i = 0; i < h.buckets_count; i++) {
    munit_assert_null(h.buckets[i]);
  }
  return MUNIT_OK;
}

MunitResult ht_test_free(const MunitParameter params[], void* user_data_or_fixture) {
  ht_str_int h = ht_str_int_new(10);
  ht_str_int_put(&h, "something", 4);
  ht_str_int_free(&h);

  munit_assert_null(h.buckets);
  munit_assert_int(h.buckets_count, ==, 0);

  return MUNIT_OK;
}

MunitResult ht_test_put(const MunitParameter params[], void* user_data_or_fixture) {
  ht_str_int h = ht_str_int_new(10);
  // 1. put the test_pairs into the table 
  for (int i = 0; i < TEST_PAIR_COUNT; i++) {
    ht_str_int_list_node *n = ht_str_int_put(&h, test_pairs[i].key, test_pairs[i].value);
  }

  // 2. assert that the table contains all of the test_pairs
  for (int i = 0; i < TEST_PAIR_COUNT; i++) {
    ht_str_int_list_node* found = 0;
    for (int j = 0; j < h.buckets_count; j++) {
      found = h.buckets[j];
      while (found && strcmp(found->key, test_pairs[i].key) != 0) found = found->next;
      if (found) break;
    }
    munit_assert_not_null(found);
  }
  return MUNIT_OK;
}

MunitResult ht_test_remove(const MunitParameter params[], void* user_data_or_fixture) {
  ht_str_int h = ht_str_int_new(10);
  // 1. put the test_pairs into the table 
  for (int i = 0; i < TEST_PAIR_COUNT; i++) {
    ht_str_int_list_node *n = ht_str_int_put(&h, test_pairs[i].key, test_pairs[i].value);
  }

  // 2. remove the test_pairs from the table
  for (int i = 0; i < TEST_PAIR_COUNT; i++) {
    ht_str_int_rem(&h, test_pairs[i].key);
  }

  // 3. assert that the table contains none of the test_pairs
  for (int i = 0; i < TEST_PAIR_COUNT; i++) {
    ht_str_int_list_node* found = 0;
    for (int j = 0; j < h.buckets_count; j++) {
      found = h.buckets[j];
      while (found && strcmp(found->key, test_pairs[i].key) != 0) found = found->next;
      if (found) break;
    }
    munit_assert_null(found);
  }

  return MUNIT_OK;
}

MunitResult ht_test_iterator(const MunitParameter params[], void* user_data_or_fixture) {
  ht_str_int h = ht_str_int_new(10);

  // 1. put the test_pairs into the table
  for (int i = 0; i < 200; i++) {
    ht_str_int_list_node *n = ht_str_int_put(&h, test_pairs[i].key, test_pairs[i].value);
  }

  // 2. assert that the table contains all of the test_pairs using the iterator
  struct {int i; ht_str_int_iter it; } v;
  for (v.it = ht_str_int_begin(&h), v.i = 0; !ht_str_int_end(&h, v.it); v.it = ht_str_int_next(&h, v.it), v.i++) {
    int i = 0;
    for (i = 0; i < 200; i++) {
      if (strcmp(test_pairs[i].key, v.it.node->key) == 0 && test_pairs[i].value == v.it.node->value) break;
    }
    munit_assert_int(i, !=, 200);
    munit_assert_string_equal(v.it.node->key, test_pairs[i].key);
    munit_assert_int(v.it.node->value, ==, test_pairs[i].value);
  }
  return MUNIT_OK;
}
