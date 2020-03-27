#include <stdio.h>
#include <math.h>

typedef unsigned long long int init;

init arr[20000010] = {};
init seg[20000010] = {};

init insuranGGWP(init x){
    if (x == 0){
        return 0;
    }
    double y = sqrt(x);
    init a = (init)y;
    init val = a * (a + 1) * (2 * a + 1) / 6;
    return ((init) val) % 10001;
}

init sum(init l, init r, init rangeL, init rangeR, init ind){
    if (rangeL <= l && rangeR >= r){
        return seg[ind];
    }

    if (l > rangeR || r < rangeL){
        return 0;
    }

    init mid = l + (r - l) / 2;
    return sum(l, mid, rangeL, rangeR, 2 * ind + 1) + sum(mid + 1, r, rangeL, rangeR, 2 * ind + 2);
}

void update(init l, init r, init i, init diff, init ind){
    if (i < l || i > r){
        return;
    }

    seg[ind] += diff;
    if (l != r){
        init mid = l + (r - l) / 2;
        update(l,mid,i,diff, ind * 2 + 1);
        update(mid+1,r,i,diff, ind * 2 + 2);
    }
}

init createSegment(init l, init r, init ind){
    if (l == r){
        seg[ind] = arr[l];
        return arr[l];
    }

    init mid = l + (r - l) / 2;

    seg[ind] = createSegment(l, mid, ind * 2 + 1) + createSegment(mid + 1, r, ind * 2 + 2);
    return seg[ind];
}

init ngotaccfixed(init x){
    if (x < 4){
        return 0;
    }
    //init qua = (init)((-b + (init)sqrt(b^2+4*a*c))/(2*a));
    init qua = (init)((-2 + (init)sqrt(2*2+4*2*x))/(2*2));

    init k = qua * qua;
    init check = 2 * (qua + 1) * qua;
    init i = 0;
    if (check + 3 <= x){
        check += 3;
        k++;
        if (check + 2 * (qua - 1) <= x){
            check += 2 * (qua - 1);
            k += (qua - 1);
            if (check + 3 <= x){
                check += 3;
                k++;
                if (check + 2 * qua <= x){
                    check += 2 * qua;
                    k += qua;
                } else {
                    k += (x - check) / 2;
                }
            }
        } else {
            k += (x - check) / 2;
        }
    }
    return k;
}

init main(){
    init n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);

    k = insuranGGWP(k);

    init i = 0;
    for (;i < n;i++){
        scanf("%lld",&arr[i]);
        if (arr[i] <= k){
            arr[i] = 0;
        } else {
            arr[i] = arr[i] - k;
        }
    }

    //Alt auto asuran

    createSegment(0,n-1,0);

    init t = 0;
    scanf("%lld",&t);
    for (i = 1;i <= t;i++){
        init what = 0;
        init a = 0;
        init b = 0;
        scanf("%lld",&what);
        if (what == 1){
            scanf("%lld%lld",&a,&b);
            init trig = 0;
            if (m <= 0){
                printf("Kasus #%lld: gagal\n",i);
                continue;
            } else {
                m--;
                init lawas = arr[a-1];
                init nyar = b;

                if (nyar <= k){
                    nyar = 0;
                } else {
                    nyar -= k;
                }

                arr[a-1] = nyar;
                init diff = nyar - lawas;
                //OFFSET -1
                update(0,n-1,a-1,diff,0);
                printf("Kasus #%lld: ok\n",i);
            }
        } else if (what == 2){
            scanf("%lld%lld",&a,&b);
            //OFFSET -1
            printf("Kasus #%lld: %lld\n",i, ngotaccfixed(sum(0,n-1,a-1,b-1,0)));
        }
    }
    //system("pausE");
    return 0;

}
